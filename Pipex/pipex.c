/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:05:33 by lalbento          #+#    #+#             */
/*   Updated: 2024/11/25 19:47:28 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void close_files(int fd1, int fd2)
{
    if (fd1 > 0)
        close(fd1);
    if (fd2 > 0)
        close(fd2);
}

int fork_process(int pipe_fd0, int pipe_fd1, int fd, char *argv, char **envp)
{
    char *final_path;
    char **cmds;
    //char *path;
    
    if (fork() == 0)
    {
        close(pipe_fd0);
        if (redirect_fd(fd, pipe_fd1) == 0)
        {
            perror("error");
            //exit(0);
            return(0);
        }
        close_files(fd, pipe_fd1);
        cmds = get_cmds(argv);
        if (!cmds)
        {
            perror("error");
            //exit(0);
            return(0);
        }
        final_path = get_final_path(get_path(envp), cmds[0]);
        if (execve_cmds(final_path,  envp, cmds) == 0)
        {
            perror("error");
            //exit(0);
            return(0);
        } 
    }
    return(1);
}

int main(int argc, char **argv, char **envp)
{
    int pipe_fd[2];
    int fd_infile;
    int fd_outfile;
    char **cmds;
    char *final_path;
    
    
    if (argc != 5)
        return(1);

    fd_infile = open(argv[1], O_RDONLY);
    fd_outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_outfile < 0)
    {
        close(fd_infile);
        perror("error");
        return (1);
    }
    if (pipe(pipe_fd) == -1)
    {
        perror("error");
        close_files(fd_infile, fd_outfile);
        return (1);
    }
    if (fork() == 0)
    {
        close(pipe_fd[0]);
        if (redirect_fd(fd_infile, pipe_fd[1]) == 0)
        {
            perror("error");
            exit(0);
        }
        close_files(fd_infile, pipe_fd[1]);
        cmds = get_cmds(argv[2]);
        final_path = get_final_path(get_path(envp), cmds[0]);
        if (execve_cmds(final_path,  envp, cmds) == 0)
        {
            perror("error");
            exit(EXIT_FAILURE);
        } 
    }
    if (fork() == 0)
    {
        close(pipe_fd[1]);
        if (redirect_fd(pipe_fd[0], fd_outfile) == 0)
        {
            perror("error");
            exit(0);
        }
        close_files(fd_outfile, pipe_fd[0]);
        cmds = get_cmds(argv[3]);
        final_path = get_final_path(get_path(envp), cmds[0]);
        if(execve(final_path, cmds, envp) == -1)
        {
            perror("error");
            exit(0);
        }
    }
    close_files(fd_infile, fd_outfile);
    close_files(pipe_fd[0], pipe_fd[1]);
    wait(0);
    return (0);
    
}
