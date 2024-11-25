/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:13:45 by lalbento          #+#    #+#             */
/*   Updated: 2024/11/25 19:50:16 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//crea una matriz con los comandos 
char **get_cmds(char *argv)
{
	char **cmds;

	cmds = ft_split(argv, ' ');
	if (!cmds)
		return (NULL);
	return(cmds);
}
//consigue las ruta de path
char    **get_path(char **envp)
{
    int i;
    char **paths;

    i = 0;
    while(envp[i])
    {
        if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			return (paths);
		}

        i++;
    }
    perror("error");
	return (NULL);
	
    
}
//encuentra la ruta buena
char *get_final_path(char **paths, char *cmd)
{
	int	i;
	char *path;
	char *tmp;

	i = 0;
	if ((ft_strncmp(cmd, "./", 2) == 0) && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	if (!paths )
		return (NULL);

	while(paths[i])
	{
		tmp = ft_strjoin(paths[i], "/" );
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if ((access(path, F_OK) == 0) && (access(path, X_OK) == 0))
			return(path);
		free(path);
		i++;
	}
	return(NULL);
}
//redirige para que se ejecuten los comandos sobre el archivo y no sobre la ruta 
int	redirect_fd(int fd_infile, int fd_outfile)
{
	if (dup2(fd_infile, STDIN_FILENO) == -1)
	{
		perror("error");
		return (0);
	}
	if(dup2(fd_outfile, STDOUT_FILENO) == -1)
	{
		perror("error");
		return (0);
	}
	return (1);
}
int execve_cmds(char *path, char **envp, char **cmds)
{
	if (!path || !cmds)
	{
		perror("error");
		return(0);
	}
	
    if (execve(path, cmds, envp) == -1) {
        perror("error");
        return (0);
    }
	return (1); 
}

