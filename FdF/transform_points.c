/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:26:36 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/16 17:08:53 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

t_point *isometric(int x, int y, int z)
{
    t_point *point = malloc(sizeof(t_point));
    double  angle;

    angle = M_PI / 6;
    point->x = (x - y) * cos(angle);
    point->y = (x + y) * sin(angle) - z;
    return (point);
}

int get_scale(t_map *map_data)
{
    int scale_x;
    int scale_y;
    int scale_z;
    int scale;

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

void    scale_points(int i, int j, int z, t_map *map_data)
{
    int scale;
    
    scale = get_scale(map_data);
    j = j * scale;
    i = i * scale;
    z = (z - map_data->min_z) * scale / 2;
}

t_point *get_point(int i, int j, int z, t_map *map_data)
{
    t_point *point = malloc(sizeof(t_point));
    int x_offset;
    int y_offset;
    int scale;
    int x;
    int y;
   
    
    scale = get_scale(map_data);
    x_offset = (MAP_WIDTH - (map_data->width * scale)) / 2;
    y_offset = (MAP_HEIGTH - (map_data->heigth * scale)) / 2;
    x = j * scale;
    y = i * scale;
    z = (z - map_data->min_z) * scale / 2;
    point = isometric(x, y, z);
    point->x += x_offset;
    point->y += y_offset;
    point->color = get_color(z, map_data);
    return (point);
}
