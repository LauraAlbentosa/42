/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:13:45 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/01 15:39:55 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_cmds(char *argv)
{
	char	**cmds;

	cmds = ft_split(argv, ' ');
	if (!cmds)
		return (NULL);
	return (cmds);
}

char	**get_path(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			if (!paths)
				return (NULL);
			return (paths);
		}
		i++;
	}
	return (NULL);
}

char	*get_final_path(char **paths, char *cmd)
{
	int		i;
	char	*path;
	char	*tmp;

	i = 0;
	if ((ft_strncmp(cmd, "./", 2) == 0) && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	if (!paths)
		return (NULL);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/" );
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if ((access(path, F_OK) == 0) && (access(path, X_OK) == 0))
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

int	redirect_fd(int fd_infile, int fd_outfile)
{
	if (fd_infile < 0 || fd_outfile < 0)
	{
		close_files(fd_infile, fd_outfile);
		return (0);
	}
	if (dup2(fd_infile, STDIN_FILENO) == -1)
	{
		perror("error");
		return (0);
	}
	if (dup2(fd_outfile, STDOUT_FILENO) == -1)
	{
		perror("error");
		return (0);
	}
	return (1);
}

int	ft_error(char *mssg)
{
	perror(mssg);
	return (0);
}
