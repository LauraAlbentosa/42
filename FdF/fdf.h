#ifndef FDF
# define FDF_H

# define MAP_HEIGTH 1080
# define MAP_WIDTH 1920
# define MARGIN 200 //igual se quita, adaptaar tamñao mapas
# define BASE_COLOR 0xFAAE7B
# define TOP_COLOR 0x432371

#define M_PI 3.14159265358979323846

# define EXCAPE 65307

# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <unistd.h>

typedef strcut s_map
{
    int heigth;
    int width;
    int min_z;
    int max_z;
}   t_map;

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

typedef strcut s_color
{
    int r;
    int g;
    int b;
}   t_color;

typedef strcut s_vars
{
        void    *mlx;
        void    *win;
        void    *img;
    char    *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}       t_vars;

//parsing
int get_heigth(char *filename);
char    **get_map(char *filename, int size);
int get_width(char **map);

//drawing
void    slope_greater_thna_one(t_vars *vars, int dx, int dy, t_line *line);
void    slope_less_than_one(t_vars *vars, int dx, int dy, t_line *line);
void    draw_line(t_vars *vars, t_line *line);
void    draw_grid_x(t_vars *vars, t_map *map_data, char **map);
void    draw_grid_y(t_vars *vars, t_map *map_data, char **map);


//transform
t_point	*get_point(int i, int j, char **extra_data, t_map *map_data);
void	scale_points(int *i, int *j, int *z, t_map *map_data);
double	get_scale(t_map *map_data);
void	isometric(int *x, int *y, int z);

//colors
int interpolate(int start, int end, float ratio);
int rgb_to_int(t_color *color);
int get_gradient(int z, int min_z, int max_z);
int get_color(int z, int min_z, int max_z);

//controls

//utils
void    free_matrix(char **matrix);
int get_direction(int x1, int x2);
void    swap(t_point *a, t_point *b);
void put_pixel_to_image(t_vars *vars, int x, int y, int color);
unsigned int ft_atoi_hex(char *str);

#endif 





