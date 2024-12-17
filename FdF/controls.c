/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:06:06 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/17 19:38:23 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int	close_window(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_image(vars->mlx, vars->img);
    exit(0);
}

int key_pressed(int keycode, t_vars *vars)
{
    if (keycode == ESCAPE)
        close_window(vars);
    return (0);
}
void cleanup_window(t_vars *vars)
{
    if (vars->win)
        mlx_destroy_window(vars->mlx, vars->win);
}
void cleanup_images(t_vars *vars)
{
    if (vars->img)
        mlx_destroy_image(vars->mlx, vars->img);
}
void cleanup_display(t_vars *vars)
{
    if (vars->mlx)
    {
        mlx_destroy_display(vars->mlx); // Solo en sistemas Linux
        free(vars->mlx);
    }
}
int close_program(t_vars *vars)
{
    cleanup_images(vars);
    cleanup_window(vars);
    cleanup_display(vars);
    exit(0);
    return (0);
}


