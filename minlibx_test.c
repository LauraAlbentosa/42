/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minlibx_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbento <lalbento@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:11:39 by lalbento          #+#    #+#             */
/*   Updated: 2024/12/02 17:11:41 by lalbento         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* gcc fdf.c -I/minilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

int main(void)
{
    void    *mlx;
    void    *mlx_win;

    mlx = mlx_init(); //
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World"); 
    la funcion mlx_new_window devuelve un puntero a la ventan creada, se le puede dar ancho alto 
    y nombre. Se llama a mlx_loop para incicar el render
    mlx_loop(mlx);
}


#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x000000FF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
*/