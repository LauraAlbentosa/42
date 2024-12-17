/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:45:29 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/17 19:10:56 by lalbento         ###   ########.fr       */
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

void put_pixel_to_image(t_vars *vars, int x, int y, int color)
{
    char *dst;

    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGTH)
    {
        dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
        *(unsigned int *)dst = color;
    }
}

unsigned int ft_atoi_hex(char *str)
{
    unsigned int num;
    int i;
    char    digit;

    i = 0;
    num = 0;
    if (str[0] == '0' && (str[1] == 'x'))
        i = 2;
    while(str[i])
    {
        digit = str[i];
        num *= 16;

        if (digit >= '0' && digit <= '9')
            num += digit - '0';
        else if (digit >= 'a' && digit <= 'f')
            num += digit - 'a' + 10;
        else if (digit >= 'A' && digit <= 'F')
            num += digit - 'A' + 10;
        else
            break;
        i++; 
    }
    return (num);
}