# include "fdf.h"

void    slope_greater_than_one(t_vars *vars, int dx, int dy, t_line *line)
{
    int p;
    int i;
    int sx;
    int sy;
   
    i = 0;
    p = 2 * dy - dx;
    sx = get_direction(line->a->x, line->b->x);
    sy = get_direction(line->a->y, line->b->y); 
    while (i <= dy)
    {
        put_pixel_to_image(vars, line->a->x, line->a->y, line->a->color);
        line->a->y += sy;
        if (p < 0)
            p += 2 * dx;
        else
        {
            line->a->x += sx;
            p += 2 * dx - 2 * dy;
        }
        i++;
    }
}

void    slope_less_than_one(t_vars *vars, int dx, int dy, t_line *line)
{
    int p;
    int i;
    int sx;
    int sy;

    i = 0;
    p = 2 * dy - dx;
    sx = get_direction(line->a->x, line->b->x);
    sy = get_direction(line->a->y, line->b->y);
    while (i <= dx)
    {
        put_pixel_to_image(vars, line->a->x, line->a->y, line->a->color);
        line->a->x += sx;
        if (p < 0)
            p = p + 2 * dy;
        else
        {
            line->a->y += sy;
            p = p + 2 * dy - 2 * dx;
        }
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
    t_line *line;

    i = 0;
    line = malloc(sizeof(t_line));
    while(map[i] && i < map_data->heigth - 1) 
    {
        data = ft_split(map[i], ' ');
        data2 = ft_split(map[i + 1], ' ');
        j = 0;
        while(data2[j])
        {
            line->a = get_point(i, j, ft_split(data[j], ','), map_data);
            line->b = get_point(i + 1, j, ft_split(data2[j], ','), map_data);
            draw_line(vars, line);
            j++;
        }
        free_matrix(data2);
        free_matrix(data);
        i++;
    }
}

void    draw_grid_x(t_vars *vars, t_map *map_data, char **map)
{
    char    **data;
    int i;
    int j;
    t_line *line;

    line = malloc(sizeof(t_line));
    i = 0;
    while(map[i])
    {
        j = 0;
        data = ft_split(map[i], ' ');
        while (j < map_data->width - 1)
        {
            line->a = get_point(i, j, ft_split(data[j], ','), map_data);
            line->b = get_point(i, j + 1, ft_split(data[j + 1], ','), map_data);
            draw_line(vars, line);
            j++;
        }
        free_matrix(data);
        i++;
    }
}
// liberar memoria de os splits en draw_lines

