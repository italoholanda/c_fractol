/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:36:45 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/13 18:45:10 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

int	check_args(char *arg)
{
	if (!ft_strncmp(arg, "mandelbrot", ft_strlen("mandelbrot"))
		|| !ft_strncmp(arg, "julia", ft_strlen("julia")))
	{
		return (0);
	}
	return (1);
}

int	mouse_hook(int keycode, t_mlx *mlx)
{
	static int	count;

	if (!count)
		count = 0;
	if (mlx)
		printf("%i\n", keycode);
	printf("%i", count);
	printf("Hello from mouse_hook!\n");
	count++;
	return (0);
}

void	make_fractol_img(t_img *img, t_mlx *mlx, char *arg)
{
	mlx_set_img(mlx, img);
	get_fractal(*img, arg);
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_img	img;

	if (argc < 2)
		return (get_few_args_err());
	if (check_args(argv[1]))
		return (get_invalid_args_err());
	mlx_set_win(&mlx);
	make_fractol_img(&img, &mlx, argv[1]);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
	mlx_loop(mlx.ptr);
}
