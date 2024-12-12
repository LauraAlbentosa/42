/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:40:42 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/11 12:37:38 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

int get_heigth(char *filename)
{
    int fd;
    int heigth;
    char    *line;

    heigth = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (0);
    line = get_next_line(fd);
    if (!line)
        return (0);
    while (line)
    {
        heigth++;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    return(heigth);
}

char    **get_map(char *filename, int size)
{
    int fd;
    int i;
    char    **map;
    char *line;

    i = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return(NULL);
    map = malloc((size + 1) * sizeof(char *));
    if (!map)
        return (NULL);
    line = get_next_line(fd);
    if (!line)
        return (NULL);
    while (line)
    {
        map[i] = line;
        line = get_next_line(fd);
        i++;
    }
    free(line);
    map[i] = NULL;
    close(fd);
    return (map);
}

int get_width(char **map)
{
    int width;
    char    **line;

    line = ft_split(map[0], ' ');
    if (!line)
        return (0);
    while (line[width])
        width++;
    return (width);
}

int get_minz(char **map)
{
    int i;
    int j;
    int minz;
    char    **line;

    i = 0;
    minz = 0;
    while (map[i])
    {
        j = 0;
        line = ft_split(map[i], ' ');
        if (!line)
            return (0);
        while(line[j])
        {
            if (minz > ft_atoi(line[j]))
                minz = ft_atoi(line[j]);
            j++;
        }
        free_matrix(line);
        i++;
    }
    return (minz);   
}

int get_maxz(char **map)
{
    int i;
    int j;
    int maxz;
    char    **line;

    i = 0;
    maxz = 0;
    while (map[i])
    {
        j = 0;
        line = ft_split(map[i], ' ');
        if (!line)
            return (0);
        while (line[j])
        {
            if (maxz < ft_atoi(line[j]))
                maxz = ft_atoi(line[j]);
            j++;
        }
        free_matrix(line);
        i++;
    }
    return (maxz);
}
