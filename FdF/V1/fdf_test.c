/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:36:16 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/09 12:39:12 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

//gcc fdf.c -I/minilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

void    draw_grid_x(void *mlx, void *win, t_map map_data, char **map)
{
    char    **line;
    int i;
    int j;
    t_point start;
    t_point end;

    i = 0;
    while(map[i])
    {
        line = ft_split(map[i], ' ');
        j = 0;
        while(j < map_data.width - 1)
        {
            start = get_point(i, j, ft_atoi(line[j]), map_data);
            end = get_point(i, j + 1, ft_atoi(line[j+1]), map_data);
            draw_line(mlx, win, start, end);
            j++;
        }
        free_matrix(line);
        i++;
        
    }
}

void    draw_grid_y(void *mlx, void *win, t_map map_data, char **map)
{
    char **line;
    char **line2;
    int i;
    int j;
    t_point start;
    t_point end;

    i = 0;
    j = 0;
    while(map[i])
    {
        line = ft_split(map[i], ' ');
        if(i < map_data.height - 1)
        {
            line2 = ft_split(map[i+1], ' ');
            j = 0;
            while(line[j])
            {
                start = get_point(i, j, ft_atoi(line[j]), map_data);
                end = get_point(i+1, j, ft_atoi(line2[j]), map_data);
                draw_line(mlx, win, start, end);
                j++;
            }
            free_matrix(line2);
        }
        free_matrix(line);
        i++;
    }
}

int main()
{
    t_vars vars;
    t_map map_data;
    
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, MAP_WIDTH, MAP_HEIGTH, "test line");
    
    map_data.height = get_height("42.fdf");
    char **map = get_map_array("42.fdf", map_data.height);
    map_data.width = get_width("42.fdf");
    map_data.min_z = get_minz(map);
    map_data.max_z = get_maxz(map);


    draw_grid_x(vars.mlx, vars.win, map_data, map);
    draw_grid_y(vars.mlx, vars.win, map_data, map);
    mlx_loop(vars.mlx);
    return(0);
}