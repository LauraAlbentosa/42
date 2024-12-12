/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chatty.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:36:16 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/12 15:22:37 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_point {
    int x;
    int y;
} t_point;

typedef struct s_map {
    int width;
    int height;
} t_map;

int rgb_to_int(double r, double g, double b) {
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}

void put_pixel(void *mlx, void *win, int x, int y, int color) {
    mlx_pixel_put(mlx, win, x, y, color);
}

void draw_line(void *mlx, void *win, t_point a, t_point b) {
    int dx = abs(b.x - a.x);
    int dy = abs(b.y - a.y);
    int sx = (a.x < b.x) ? 1 : -1;
    int sy = (a.y < b.y) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        put_pixel(mlx, win, a.x, a.y, 0x0FAE3);
        if (a.x == b.x && a.y == b.y) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            a.x += sx;
        }
        if (e2 < dx) {
            err += dx;
            a.y += sy;
        }
    }
}

int get_width(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return -1;
    }

    char buffer[1];
    int width = 0;
    int in_number = 0;
    while (read(fd, buffer, 1)) {
        if (buffer[0] != ' ' && buffer[0] != '\n' && !in_number) {
            in_number = 1;
            width++;
        } else if (buffer[0] == ' ') {
            in_number = 0;
        } else if (buffer[0] == '\n') {
            break;
        }
    }
    close(fd);
    return width;
}

int get_height(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return -1;
    }

    char buffer[1];
    int height = 0;
    while (read(fd, buffer, 1)) {
        if (buffer[0] == '\n') {
            height++;
        }
    }
    close(fd);
    return height;
}

void draw_grid(void *mlx, void *win, t_map map) {
    for (int y = 0; y < map.height; y++) {
        for (int x = 0; x < map.width; x++) {
            if (x + 1 < map.width) {
                draw_line(mlx, win, (t_point){x * 20, y * 20}, (t_point){(x + 1) * 20, y * 20});
            }
            if (y + 1 < map.height) {
                draw_line(mlx, win, (t_point){x * 20, y * 20}, (t_point){x * 20, (y + 1) * 20});
            }
        }
    }
}

int main() {
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 800, 600, "FDF Grid");

    t_map map;
    map.width = get_width("42.fdf");
    map.height = get_height("42.fdf");
    if (map.width < 0 || map.height < 0) {
        return 1;
    }

    draw_grid(mlx, win, map);
    mlx_loop(mlx);
    return 0;
}


t_point get_point(int x, int y, int z, t_map map_data)
{
    t_point point;
    int scale_x = MAP_WIDTH / map_data.width;  // Escala horizontal
    int scale_y = MAP_HEIGTH / map_data.height; // Escala vertical
    
    point.x = ((x - y) * cos(0.523599)) * scale_x;
    point.y = ((x + y) * sin(0.523599) - z) * scale_y;

    return(point);
}





//V1 draw_grid

void    draw_grid(void *mlx, void *win, t_map map_data, char **map)
{
    char **line;
    char **line2;
    t_point start;
    t_point end;
    int x;
    int y;

    y = 0;
    while(y < map_data.height)
    {
        line = ft_split(map[y], ' ');
        
        x = 0;
        while(x < map_data.width)
        {
            if (x < map_data.width - 1)
            {
                start = get_point(y, x, ft_atoi(line[x]), map_data);
                end = get_point(y, x+1, ft_atoi(line[x+1]), map_data);
                draw_line(mlx, win, start, end);
            }
            if (y < map_data.height - 1)
            {
                line2 = ft_split(map[y+1], ' ');
                start = get_point(y, x, ft_atoi(line[x]), map_data);
                end = get_point(y+1, x, ft_atoi(line2[x]), map_data);
                draw_line(mlx, win, start, end);
                free_matrix(line2);
            }
            x++;
        }
        free_matrix(line);
        y++;
    }
}

//esto hace el progrma funcionar pero no entiendod porque XD

void draw_line(void *mlx, void *win, t_point start, t_point end)
{
    int dx = abs(end.x - start.x);
    int dy = abs(end.y - start.y);
    int sx = (start.x < end.x) ? 1 : -1;
    int sy = (start.y < end.y) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        mlx_pixel_put(mlx, win, start.x, start.y, 0x00FAE3);
        if (start.x == end.x && start.y == end.y)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            start.x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            start.y += sy;
        }
    }
}


int	get_default_color(int z, t_map *map_data)
{
	double			percent;
	unsigned int	max;

	max = map_data->max_z - map_data->min_z;
	if (max == 0)
		return (0x432371);
	percent = ((double)(z - map_data->min_z) / max);
	if (percent < 0.2)
		return (0x432371);
	else if (percent < 0.4)
		return (0x714674);
	else if (percent < 0.6)
		return (0x9F6976);
	else if (percent < 0.8)
		return (0xCC8B79);
	else
		return (0xFAAE7B);
}
