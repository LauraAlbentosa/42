/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:45:29 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/12 16:22:51 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void    free_matrix(char **matrix)
{
    int i;

    if (!matrix)
        return;
    i = 0;
    while (matrix[i]) 
    {
        free(matrix[i]); 
        i++;
    }
    free(matrix);
}

void    put_pixel(void *mlx, void *win, t_point *a)
{   
    mlx_pixel_put(mlx, win, a->x, a->y, a->color);
}
int get_direction(int x1, int x2)
{
    int sx;

    if (x1 < x2)
        sx = 1;
    else
        sx = -1;
    return (sx);
}

void    swap(t_point *a, t_point *b)
{
    t_point tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int	my_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
