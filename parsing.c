/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:30:38 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/04 18:24:46 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int get_height(char *filename)
{
    int fd;
    int height;
    char    *line;

    height = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return(0);
    line = get_next_line(fd);
    while(line)
    {
        free(line);
        line = get_next_line(fd);
        height++;
    }
    free(line);
    close(fd);
    return(height);
}

int get_width(char *filename)
{
    int fd;
    int i;
    int width;
    char *line;
    char    **array_line;

    i = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (0);
    line = get_next_line(fd);
    array_line = ft_split(line, ' ');
    while(array_line[width])
        width++;
    free(line);
    while(array_line[i])
    {
        free(array_line[i]);
        i++;
    }
    free(array_line);
    close(fd);
    return(width);
}

char    **get_map_array(char *filename, int size)
{
    int fd;
    int i;
    char    **array_map;
    char    *line;

    i = 0;
    
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return(NULL);
    line = get_next_line(fd);
    array_map = malloc((size + 1) *sizeof(char *));
    if (!array_map)
        return(NULL);
    while(line)
    {
        array_map[i] = line;
        line = get_next_line(fd);
        i++;
    }
    free(line);
    array_map[i] = NULL;
    close(fd);
    return(array_map);
}

//Esta función genera los puntos de una línea
t_point get_points_from_map(char **array_map, int i, int j)
{
    char    **tmp_array;
    t_point point;

    tmp_array = ft_split(array_map[i], ' ');
    
    while(tmp_array[i])
    {
        point.x = j;
        point.y = i;
        break;
    }
        //point.z = ft_atoi(tmp_array[j]);
        //printf("esto son las x:%i, esto son las y: %i, y esto es z: %i\n", point.x, point.y, point.z);
    return(point);
}

/*
int main(void)
{
    int height = get_height("42.fdf");
    char **array = get_map_array("42.fdf", height);
    int width  = get_width("42.fdf");

    int i = 0;
    printf("la atura: %i\n", height);
    printf("el ancho: %i\n", width);
    
    get_points_from_map(array, width, height);
    
    return(0);
}
*/