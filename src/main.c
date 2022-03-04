/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:36:45 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/04 17:17:29 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int main(void)
{
	t_mlx	mlx;
	t_img	img;

	mlx_set_win(&mlx);
	mlx_set_img(&mlx, &img);
	get_mandelbrot(img);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.ptr);
}
