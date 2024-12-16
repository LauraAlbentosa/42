/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:25:03 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/16 17:19:16 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

/*
int rgb_to_int(int r, int g, int b)
{
    int color = 0;
    
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}

int   gradient_fraction(t_point *a, t_point *b)
{
    int fraction;

    if (abs(a->x - b->x) > abs(a->y - b->y))
        fraction = abs(a->x - b->x);
    else
        fraction = abs(a->y - b->y);
    return (fraction);
    return sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2));
}
t_color *get_color_gradient(int fraction, t_color *color1, t_color *color2)
{
    t_color *color_increment =  malloc(sizeof(t_color));
    if (!color_increment)
        return(0);

    color_increment->r = (int)(color1->r + (color2->r - color1->r) / (1.0/fraction));
    color_increment->g = (int)(color1->g + (color2->g - color1->g) / (1.0/fraction));
    color_increment->b = (int)(color1->b + (color2->b - color1->b) / (1.0/fraction));

    return (color_increment);
}
int get_final_color(t_color *increment, t_color *base_color)
{
    t_color *final_color = malloc(sizeof(t_color));
    int final;
    
    final_color->r = increment->r + base_color->r;
    final_color->g = increment->g + base_color->g;
    final_color->b = increment->b + base_color->b;
    
    final = rgb_to_int(final_color->r, final_color->g, final_color->b);
    return (final);
}

int get_color(int z, t_map *map_data)
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
		return (0x432371);
	else
		return (0xFAAE7B);
}


int gradient(int color1, int color2, int z, t_map *map_data, t_point *a)
{
    int inc;
    int steps;

    inc = color1 - color2;
    steps = ...;
    final_inc = inc/steps;

    final_color = color1 + fina_inc;
    return(final_inc);
    
}


int get_color(int z, t_map *map_data)
{
    int color;
    
    if (map_data->max_z == map_data->min_z)
        color = 0x432371;
    else if (z == map_data->max_z)
        color = 0xFAAE7B;
    else if (z == map_data->min_z)
        color = 0x432371;
    return(color);
}

*/


int get_color(int height, t_map *map_data)
{
    double ratio;
    int r;
    int b;

    ratio = (double)(height - map_data->min_z) / (map_data->max_z - map_data->min_z);
    r = (int)(ratio * 255);
    b = (int)((1 - ratio) * 255);
    return (r << 16) | (b);
}

int interpolate_color(int color1, int color2, double t) 
{
    int red = ((1 - t) * ((color1 >> 16) & 0xFF)) + (t * ((color2 >> 16) & 0xFF));
    int green = ((1 - t) * ((color1 >> 8) & 0xFF)) + (t * ((color2 >> 8) & 0xFF));
    int blue = ((1 - t) * (color1 & 0xFF)) + (t * (color2 & 0xFF));
    return (red << 16) | (green << 8) | blue;
}
