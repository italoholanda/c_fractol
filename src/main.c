/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:36:45 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/20 17:25:13 by igomes-h         ###   ########.fr       */
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

// void	make_fractol_img(t_img *img, t_mlx *mlx, char *arg)
// {
// 	mlx_set_img(mlx, img);
// 	get_fractal(*img, arg);
// 	mlx_put_image_to_window(mlx->ptr, mlx->win, img->img, 0, 0);
// }

int	main(int argc, char **argv)
{
	t_xdata	xdata;

	if (argc < 2)
		return (get_few_args_err());
	if (check_args(argv[1]))
		return (get_invalid_args_err());
	mlx_set_win(&xdata);
	mlx_set_img(&xdata);
	get_fractal(xdata, argv[1]);
	mlx_put_image_to_window(xdata.mlx_ptr, xdata.win_ptr, xdata.img_ptr, 0, 0);
	mlx_loop(xdata.mlx_ptr);
}
