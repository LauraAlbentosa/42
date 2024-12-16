/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:51:48 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/16 17:23:46 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void    slope_greater_than_one(t_vars *vars, int dx, int dy, t_line *line)
{
    int p;
    int i;
    int sx;
    int sy;
    double t;
   
    i = 0;
    p = 2 * dy - dx;
    sx = get_direction(line->a->x, line->b->x);
    sy = get_direction(line->a->y, line->b->y);
    
    while (i <= dy)
    {
        t = (double)i / dy; // Proporción entre 0 y 1
        int color = interpolate_color(line->a->color, line->b->color, t);
        put_pixel(vars->mlx, vars->win, line->a, color);
        line->a->y += sy;
        if (p < 0)
            p += 2 * dx;
        else
        {
            line->a->x += sx;
            p += 2 * dx - 2 * dy;
        }
        //put_pixel(vars->mlx, vars->win, line->a, color);
        i++;
    }
}

void    slope_less_than_one(t_vars *vars, int dx, int dy, t_line *line)
{
    int p;
    int i;
    int sx;
    int sy;
    double t;

    i = 0;
    p = 2 * dy - dx;
    sx = get_direction(line->a->x, line->b->x);
    sy = get_direction(line->a->y, line->b->y);
    
    
    while (i <= dx)
    {
        t = (double)i / dx; // Proporción entre 0 y 1
        int color = interpolate_color(line->a->color, line->b->color, t);
        put_pixel(vars->mlx, vars->win, line->a, color);
        line->a->x += sx;
        if (p < 0)
            p = p + 2 * dy;
        else
        {
            line->a->y += sy;
            p = p + 2 * dy - 2 * dx;
        }
        //put_pixel(vars->mlx, vars->win, line->a, color);
        i++;
    }
}

void    draw_line(t_vars *vars, t_line *line)
{
    int dx;
    int dy;

    dx = abs(line->b->x - line->a->x);
    dy = abs(line->b->y - line->a->y);
    if ( abs(dy) <= abs(dx))
    {
        if (line->a->x > line->b->x)
            swap(line->a, line->b);
        slope_less_than_one(vars, dx, dy, line);
    }
    else
    {
        if( line->a->y > line->b->y)
            swap(line->a, line->b);
        slope_greater_than_one(vars, dx, dy, line);
    }
}

void    draw_grid_y(t_vars *vars, t_map *map_data, char **map)
{
    char    **data;
    char    **data2;
    int i;
    int j;
    t_line *line = malloc(sizeof(t_line));

    i = 0;
    while(map[i]) 
    {
        data = ft_split(map[i], ' ');
        if (i < map_data->heigth - 1)
        {
            j = 0;
            data2 = ft_split(map[i + 1], ' ');
            while(data2[j])
            {
                line->a = get_point(i, j, ft_atoi(data[j]), map_data);
                line->b = get_point(i + 1, j, ft_atoi(data2[j]), map_data);
                draw_line(vars, line);
                j++;
            }
            free_matrix(data2);
        }
        free_matrix(data);
        i++;
    }
}

void    draw_grid_x(t_vars *vars, t_map *map_data, char **map)
{
    char    **data;
    int i;
    int j;
    t_line *line = malloc(sizeof(t_line));

    i = 0;
    while(map[i])
    {
        j = 0;
        data = ft_split(map[i], ' ');
        while (j < map_data->width - 1)
        {
            line->a = get_point(i, j, ft_atoi(data[j]), map_data);
            line->b = get_point(i, j + 1, ft_atoi(data[j + 1]), map_data);
            draw_line(vars, line);
            j++;
        }
        free_matrix(data);
        i++;
    }
}


