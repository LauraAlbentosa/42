/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:47:17 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/01 16:30:52 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_files(int fd1, int fd2)
{
	if (fd1 > 0)
		close(fd1);
	if (fd2 > 0)
		close(fd2);
}

int	fork_process(int pipe_fd[2], int fd_infile, char **envp, char *argv)
{
	int		pip;
	char	**cmds;
	char	*final_path;

	pip = fork();
	if (pip == -1)
		return (ft_error("error in fork"));
	else if (pip == 0)
	{
		close(pipe_fd[0]);
		if (!redirect_fd(fd_infile, pipe_fd[1]))
			return (ft_error("error in dup2"));
		cmds = get_cmds(argv);
		final_path = get_final_path(get_path(envp), cmds[0]);
		if (execve(final_path, cmds, envp) == -1)
			return (ft_error("error in exevec"));
	}
	return (1);
}

int	fork_process2(int pipe_fd[2], int fd_outfile, char **envp, char *argv)
{
	int		pip;
	char	**cmds;
	char	*final_path;

	pip = fork();
	if (pip == -1)
		return (ft_error("error in fork"));
	else if (pip == 0)
	{
		close(pipe_fd[1]);
		if (!redirect_fd(pipe_fd[0], fd_outfile))
			return (ft_error("error in dup2"));
		cmds = get_cmds(argv);
		final_path = get_final_path(get_path(envp), cmds[0]);
		if (execve(final_path, cmds, envp) == -1)
			return (ft_error("error in execve"));
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int	pipe_fd[2];
	int	fd_infile;
	int	fd_outfile;

	if (argc != 5)
	{
		perror("error");
		return (1);
	}
	fd_infile = open(argv[1], O_RDONLY);
	fd_outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipe(pipe_fd) == -1)
	{
		perror("error in pipe");
		close_files(fd_infile, fd_outfile);
		return (1);
	}
	if (!fork_process(pipe_fd, fd_infile, envp, argv[2]))
		exit(0);
	if (!fork_process2(pipe_fd, fd_outfile, envp, argv[3]))
		exit(0);
	close_files(fd_infile, fd_outfile);
	close_files(pipe_fd[0], pipe_fd[1]);
	return (wait(0), wait(0), 0);
}
