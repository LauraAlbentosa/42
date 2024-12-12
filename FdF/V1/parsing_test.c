/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:30:38 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/09 12:40:41 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int get_width(char *filename)
{
    int fd;
    int i;
    int width;
    char *line;
    char    **array_line;

    i = 0;
    width = 0;
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


int get_minz(char **map)
{
    int i;
    int j;
    int min;
    char **line;

    i = 0;
    min = 0;
    while(map[i])
    {
        j = 0;
        line = ft_split(map[i], ' ');
        while(line[j])
        {
            if (min > ft_atoi(line[j]))
                min = ft_atoi(line[j]);
            j++;  
        }
        i++;
    }
    return (min);
}

int get_maxz(char **map)
{
    int i;
    int j;
    int max;
    char **line;

    i = 0;
    max = 0;
    while(map[i])
    {
        j = 0;
        line = ft_split(map[i], ' ');
        while(line[j])
        {
            if (max < ft_atoi(line[j]))
                max = ft_atoi(line[j]);
            j++;  
        }
        i++;
    }
    return (max);
}