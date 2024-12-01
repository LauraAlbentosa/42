/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:59:01 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/01 16:31:43 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include "Libft/libft.h"

char	**get_path(char **envp);
char	*get_final_path(char **paths, char *cmd);
char	**get_cmds(char *argv);
int		redirect_fd(int fd_infile, int fd_outfile);
int		ft_error(char *mssg);
void	close_files(int fd1, int fd2);

#endif
