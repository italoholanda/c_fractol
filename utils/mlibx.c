/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlibx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:14:05 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/02 11:48:08 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int mlibx_handle_no_event(void *data)
{
	return (0);
}

int mlibx_handle_input(int keysym, t_mlx *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int mlibx_init_screen(t_mlx data)
{
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, SIZEX, SIZEY, "FRACT'OL");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	return (0);
}

void draw_pixel_img(t_img *img, int x, int y, int color)
{
	char *dst;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_pixel(t_img img, long double x, long double y)
{
	draw_pixel_img(&img, x, y, 0x00FF0000);
}

int mlibx_keep_screen(t_mlx data, int *f_no_event, int *f_input)
{
	mlx_loop_hook(data.mlx_ptr, f_no_event, &data);
	mlx_key_hook(data.win_ptr, f_input, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
