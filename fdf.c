/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:36:16 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/04 18:37:33 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

//gcc fdf.c -I/minilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}

void    put_pixel(void *mlx, void *win, int x , int y)
{
    mlx_pixel_put(mlx, win, x, y, 0x0FAE3);
}
void slope_greater_than_one(void *mlx, void *win, int dx, int dy, t_point *a) 
{
    int p = 2 * dx - dy;
    int i = 0;

    put_pixel(mlx, win, a->x, a->y);
    while (i < dy) {
        a->y += 1;
        if (p < 0) {
            p += 2 * dx;
        } else {
            a->x += 1;
            p += 2 * dx - 2 * dy;
        }
        put_pixel(mlx, win, a->x, a->y);
        i++;
    }
}

void slope_less_than_one(void *mlx, void *win, int dx, int dy, t_point *a)
{
    int p;
    int     i;
    
    i = 0;
    p = 2*dy - dx;
    put_pixel(mlx, win, a->x, a->y);
    while(i < dx)
    {
        a->x += 1;
        if (p < 0)
            p = p + 2 * dy;
        else
        {
            a->y += 1;
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

    if (abs(dy) <= abs(dx))
    {
        if (a.x > b.x)
        {
            t_point temp;
            temp = a;
            a = b;
            b = temp;
        }
        slope_less_than_one(mlx, win, dx, dy, &a);
    }
    else
    {
        if (a.y > b.y)
        {
            t_point temp;
            temp = a;
            a = b;
            b = temp;
        }
        slope_greater_than_one(mlx, win, dx, dy, &a);
    }
}


void    draw_cuad(void *mlx, void *win, char *filename)
{
    t_map map_data;
    t_point start;
    t_point end;

    map_data.width = get_width(filename);
    map_data.height = get_height(filename);


    start.x = 0;
    start.y = 0;
    end.x = map_data.width - 1;
    end.y = 0;
    draw_line(mlx, win, start, end);
    
}


int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 800, 600, "test line");
    //int height = get_height("42.fdf");
    //char **map = get_map_array("42.fdf", height);

    
    draw_cuad(mlx, win, "42.fdf");
    mlx_loop(mlx);
    return(0);
}