/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:38:59 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/17 19:39:09 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int main(int argc, char **argv)
{
    t_vars *vars = malloc(sizeof(t_vars));
    t_map *map_data = malloc(sizeof(t_map));
    char **map;
    char    *map_name;
    
    if (argc != 2)
        return(1);
    map_name = argv[argc - 1];
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx, MAP_WIDTH, MAP_HEIGTH, "Fdf");

    vars->img = mlx_new_image(vars->mlx, MAP_WIDTH, MAP_HEIGTH);
    vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
    
    map_data->heigth = get_heigth(map_name);
    map = get_map(map_name, map_data->heigth);
    map_data->width = get_width(map);
    map_data->min_z = get_minz(map);
    map_data->max_z = get_maxz(map);

    draw_grid_x(vars, map_data, map);
    draw_grid_y(vars, map_data, map);

    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);

    mlx_hook(vars->win, 2, 1L<<0, key_pressed, vars);
    mlx_hook(vars->win, 17, 1L<<17, close_program, vars);
    mlx_loop(vars->mlx);
    
    free_matrix(map);
    free(vars);
    free(map_data);
    return (0);
}

  