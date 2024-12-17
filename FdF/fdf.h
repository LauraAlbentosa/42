/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:12:24 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/17 19:24:08 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#  define MAP_HEIGTH 1080
#  define MAP_WIDTH 1920
#  define MARGIN 200
#  define BASE_COLOR 0xFAAE7B
#  define TOP_COLOR 0x432371

#define M_PI 3.14159265358979323846

# define ESCAPE 65307


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
    void    *img;
    char    *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
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
void    free_matrix(char **matrix);
int get_direction(int x1, int x2);
void    swap(t_point *a, t_point *b);
void put_pixel_to_image(t_vars *vars, int x, int y, int color);
unsigned int ft_atoi_hex(char *str);

//transform points
t_point *get_point(int i, int j, char **extra_data, t_map *map_data);
void isometric(int *x, int *y, int z);
double get_scale(t_map *map_data);
void    scale_points(int *i, int *j, int *z, t_map *map_data);

//color
int rgb_to_int(int r, int g, int b);
int get_color(int z, t_map *map_data);
int interpolate_color(int color1, int color2, double t);

//controls
int	close_window(t_vars *vars);
int key_pressed(int keycode, t_vars *vars);

#endif