/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:57:46 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/12 16:00:21 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void slope_greater_than_one(void *mlx, void *win, int dx, int dy, t_point *a, t_point *b) 
{
    int p;
    int i;
    int sx; //controla la dirección
    int sy;

    i = 0;
    dy = abs(dy);
    dx = abs(dx);
    p = 2 * dx - dy;
    if (a->x < b->x)
        sx = 1;
    else
        sx = -1;
    if (a->y < b->y)
        sy = 1;
    else
        sy = -1;
    put_pixel(mlx, win, a);
    while (i < dy) 
    {
        a->y += sy;
        if (p < 0) 
            p += 2 * dx;
        else 
        {
            a->x += sx;
            p += 2 * dx - 2 * dy;
        }
        put_pixel(mlx, win, a);
        i++;
    }
}



void slope_less_than_one(void *mlx, void *win, int dx, int dy, t_point *a, t_point *b)
{
    int p;
    int     i;
    int sx;
    int sy;
    
    i = 0;
    dy = abs(dy);
    dx = abs(dx);
    p = 2*dy - dx;
    if(a->x < b->x)
        sx = 1;
    else
        sx = -1;
    if(a->y < b->y)
        sy = 1;
    else
        sy = -1;
    put_pixel(mlx, win, a->x, a->y);
    while(i < dx)
    {
        a->x += sx;
        if (p < 0)
            p = p + 2 * dy;
        else
        {
            a->y += sy;
            p = p + 2 * dy - 2 * dx;
        }
        put_pixel(mlx, win, a->x, a->y);
        i++;
    }
    
}
void    draw_line(void *mlx, void *win, t_point a, t_point b)
{
    int dx = b.x - a.x;
    int dy = b.y - a.y;
    t_point temp;

    if (abs(dy) <= abs(dx))
    {
        if (a.x > b.x)
        {
            temp = a;
            a = b;
            b = temp;
        }
        slope_less_than_one(mlx, win, dx, dy, &a, &b);
    }
    else
    {
        if (a.y > b.y)
        {  
            temp = a;
            a = b;
            b = temp;
        }
        slope_greater_than_one(mlx, win, dx, dy, &a, &b);
    }
}

t_point project_isometric(int x, int y, int z)
{
    t_point projected;
    double angle = M_PI / 6; // 30 degrees in radians

    projected.x = (x - y) * cos(angle);
    projected.y = (x + y) * sin(angle) - z;
    return (projected);
}

t_point get_point(int i, int j, int z, t_map map_data)
{
    t_point point;
    int margin = 300;
    // Escalado (opcional para ajustar al tamaño del mapa en la ventana)
    int scale_x = (MAP_WIDTH - margin * 2)/map_data.width;
    int scale_y = (MAP_HEIGTH - margin * 2)/map_data.height;
    int scale_z = (MAP_HEIGTH - margin *2)/(map_data.max_z - map_data.min_z);
    int scale;
    
    if (scale_x < scale_y)
        scale = scale_x;
    else
        scale = scale_y;
        
    if ( map_data.max_z - map_data.min_z > 0)
    {
        if ( scale > scale_z)
            scale = scale_z;
    }
    
    
    int x_offset = (MAP_WIDTH - (map_data.width * scale)) / 2;
    int y_offset = (MAP_HEIGTH - (map_data.height * scale)) / 2;

    // Coordenadas base escaladas
    int x = j * scale;
    int y = i * scale;
    z = (z - map_data.min_z) * scale / 2; // Reduce la altura relativa para más realismo

    // Proyección isométrica
    point = project_isometric(x, y, z);

    // Ajustes para centrar en la ventana
    point.x += x_offset;
    point.y += y_offset;
    return (point);
}
