/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:26:36 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/17 19:13:43 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void isometric(int *x, int *y, int z)
{
    //t_point *point = malloc(sizeof(t_point));
    double  angle;
    int prev_x = *x;
    int prev_y = *y;

    angle = M_PI / 6;
    *x = (prev_x - prev_y) * cos(angle);
    *y = (prev_x + prev_y) * sin(angle) - z;
    //return (point);
}

double get_scale(t_map *map_data)
{
    double scale_x;
    double scale_y;
    double scale_z;
    double scale;

    scale_x = (MAP_WIDTH - (MARGIN * 2))/map_data->width;
    scale_y = (MAP_HEIGTH - (MARGIN * 2))/map_data->heigth;
    scale_z = (MAP_HEIGTH - (MARGIN * 2))/(map_data->max_z - map_data->min_z);

    if (scale_x < scale_y)
        scale = scale_x;
    else
        scale = scale_y;
    if ((map_data->max_z - map_data->min_z) > 0)
    {
        if (scale > scale_z)
            scale = scale_z;
    }
    return (scale);
}

void    scale_points(int *i, int *j, int *z, t_map *map_data)
{
    double scale;
    
    scale = get_scale(map_data);
    *j = (int)(*j * scale);
    *i = (int)(*i * scale);
    *z = (int)(*z - map_data->min_z) * scale / 2;
}

t_point *get_point(int i, int j, char **extra_data, t_map *map_data)
{
    t_point *point = malloc(sizeof(t_point));
    int x_offset;
    int y_offset;
    double scale;
    int x;
    int y;
    int z;
   

    z = ft_atoi(extra_data[0]);
    scale = get_scale(map_data);
    x_offset = (MAP_WIDTH - (map_data->width * scale)) / 2;
    y_offset = (MAP_HEIGTH - (map_data->heigth * scale)) / 2;
    scale_points(&i, &j, &z, map_data);
    x = j;
    y = i;
    isometric(&x, &y, z);
    point->x = x + x_offset;
    point->y = y + y_offset;
    if (!extra_data[1])
        point->color = get_color(z, map_data);
    else
        point->color = ft_atoi_hex(extra_data[1]);
    return (point);
}

//cambiar todos los dobules a int para vovler al punto anterior en cuanto a escala
