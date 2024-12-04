/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:12:24 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/04 18:20:06 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H


# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <unistd.h>

typedef struct s_point
{
    int x;
    int y;
}   t_point;

typedef struct s_map
{
    int height;
    int width;
}   t_map;

int get_height(char *filename);
int get_width(char *filename);
char    **get_map_array(char *filename, int size);
t_point get_points_from_map(char **array_map, int i, int j);
#endif