/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:12:24 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/12 16:04:01 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef MAP_HEIGTH
#  define MAP_HEIGTH 1080
# endif

# ifndef MAP_WIDTH
#  define MAP_WIDTH 1920
# endif

# ifndef MARGIN
#  define MARGIN 300
# endif

# ifndef BASE_COLOR_R
#  define BASE_COLOR_R 255
# endif

# ifndef BASE_COLOR_G
#  define BASE_COLOR_G 255
#endif

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <unistd.h>


typedef struct s_color
{
    int r;
    int g;
    int b;
}   t_color;


typedef struct s_point
{
    int x;
    int y;
    int z;
    int color;
}   t_point;


typedef struct s_line
{
    t_point *a;
    t_point *b;
}   t_line;

typedef struct s_map
{
    int heigth;
    int width;
    int min_z;
    int max_z;
}   t_map;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

//parsing
int get_heigth(char *filename);
int get_width(char **map);
int get_minz(char **map);
int get_maxz(char **map);
char    **get_map(char *filename, int size);

//draw
void slope_greater_than_one(t_vars *vars, int dx, int dy, t_line *line);
void slope_less_than_one(t_vars *vars, int dx, int dy, t_line *line);
void    draw_line(t_vars *vars, t_line *line);
void    draw_grid_x(t_vars *vars, t_map *map_data, char **map);
void    draw_grid_y(t_vars *vars, t_map *map_data, char **map);

//utils
void    put_pixel(void *mlx, void *win, t_point *a);
void    free_matrix(char **matrix);
int get_direction(int x1, int x2);
void    swap(t_point *a, t_point *b);
int	my_close(t_vars *vars);

//transform points
t_point *get_point(int i, int j, int z, t_map *map_data);
t_point *isometric(int x, int y, int z);
int get_scale(t_map *map_data);
void    scale_points(int i, int j, int z, t_map *map_data);

//color
int rgb_to_int(int r, int g, int b);
int get_color(int z, t_map *map_data);

#endif