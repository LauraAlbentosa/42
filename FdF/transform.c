# include "fdf.h"

void	isometric(int *x, int *y, int z)
{
	double	angle;
	int		prev_x;
	int		prev_y;

	angle = M_PI / 6;
	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(angle);
	*y = (prev_x + prev_y) * sin(angle) - z;
}
double	get_scale(t_map *map_data)
{
	double	scale_x;
	double	scale_y;
	double	scale_z;
	double	scale;

	scale_x = (MAP_WIDTH - (MARGIN * 2)) / (double)map_data->width;
	scale_y = (MAP_HEIGTH - (MARGIN * 2)) / (double)map_data->heigth;
	if (map_data->max_z - map_data->min_z != 0)
		scale_z = (MAP_HEIGTH - (MARGIN * 2))
			/ (double)(map_data->max_z - map_data->min_z);
	else
		scale_z = scale_y;
	scale = fmin(scale_x, scale_y);
	scale = fmin(scale, scale_z);
	return (scale * 0.8);
}
void	scale_points(int *i, int *j, int *z, t_map *map_data)
{
	double	scale;
	double	scaled_z;

	scale = get_scale(map_data);
	*i = (int)((double)*i * scale);
	*j = (int)((double)*j * scale);
	scaled_z = ((double)(*z - map_data->min_z)) * (scale / 2);
	*z = (int)scaled_z;
}
static void	point_data(t_point *point, int x, int y, char **extra_data, t_map *map_data)
{
	if (!extra_data[1])
		point->color = get_color(ft_atoi(extra_data[0]), map_data);
	else
		point->color = ft_atoi_hex(extra_data[1]);
	point->x = x;
	point->y = y;
}

t_point	*get_point(int i, int j, char **extra_data, t_map *map_data)
{
	t_point	*point;
	double	scale;
	int		x;
	int		y;
	int		z;

	point = malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	z = ft_atoi(extra_data[0]);
	scale = get_scale(map_data);
	scale_points(&i, &j, &z, map_data);
	x = j;
	y = i;
	isometric(&x, &y, z);
	x += MAP_WIDTH / 2;
	y += MAP_HEIGTH / 2;
	point_data(point, x, y, extra_data, map_data);
	return (point);
}
