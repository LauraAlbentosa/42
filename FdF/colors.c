# include "fdf.h"

int interpolate(int start, int end, float ratio)
{
    int inter;
    inter = (int)(start + (end - start) * ratio);
    return (inter);
}

int rgb_to_int(t_color *color)
{
    int result;

    result = 0;
    result |= (int)(color->r * 255) << 16;
    result |= (int)(color->g * 255) << 8;
    result |= (int)(color->b * 255);
    return (result);
}

int get_gradient(int z, int min_z, int max_z)
{
    float ratio;
    int final_color;
    t_color *color;

    color = malloc(sizeof(t_color));
    if (!color)
        return(0);

    if (max_z == min_z)
        ratio = 1;
    else 
        ratio = (float)(z - min_z) / (max_z - min_z);
    
    color->r = interpolate((start_color >> 16) & 0xFF, (end_color >> 16) & 0xFF, ratio);
	color->g = interpolate((start_color >> 8) & 0xFF, (end_color >> 8) & 0xFF, ratio);
	color->b = interpolate(start_color & 0xFF, end_color & 0xFF, ratio);

    final_color = rgb_to_int(color);
    return(final_color);
}

int get_color(int z, int min_z, int max_z)
{
    int color;

    if (z == max_z)
        color = TOP_COLOR;
    else if (z == min_z)
        color = BASE_COLOR;
    else
        color = get_gradient(z, min_z, max_z);

    return (color);
}
