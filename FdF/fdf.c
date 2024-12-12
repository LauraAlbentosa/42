/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:38:59 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/12 16:07:29 by lalbento         ###   ########.fr       */
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
    map_data->heigth = get_heigth(map_name);
    map = get_map(map_name, map_data->heigth);
    map_data->width = get_width(map);
    map_data->min_z = get_minz(map);
    map_data->max_z = get_maxz(map);
    draw_grid_x(vars, map_data, map);
    draw_grid_y(vars, map_data, map);
    mlx_hook(vars->win, 2, 1L<<0, my_close, vars);
    mlx_loop(vars->mlx);
    return (0);
}

  