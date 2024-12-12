

# include "fdf.h"


int rgb_to_int(int r, int g, int b)
{
    int color = 0;
    
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}

int   get_fraction(int x1, int x2, int x)
{
    if (x1 != x2)
        return ((x - x1)/(x2 - x1));
    return (0);
}

int   gradient_fraction(t_point *a, t_point *b)
{
    int fraction;

    if (abs(a->x - b->x) > abs(a->y - b->y))
        fraction = abs(a->x - b->x);
    else
        fraction = abs(a->y - b->y);
    return (fraction);
    /*return sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2));*/
}

t_color *get_color_point(int z)
{
    t_color *color = malloc(sizeof(t_color));
    if (!color)
        return(0);
    color->r = BASE_COLOR_R;
    color->g = BASE_COLOR_G;
    color->b = z;
    return (color);
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

t_color *get_final_color(t_color *increment, t_color *base_color)
{
    t_color *final_color = malloc(sizeof(t_color));
    
    final_color->r = increment->r + base_color->r;
    final_color->g = increment->g + base_color->g;
    final_color->b = increment->b + base_color->b;
    
    return (final_color);
}

