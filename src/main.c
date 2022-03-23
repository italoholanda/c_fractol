/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:36:45 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/22 22:12:32 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdlib.h>
#include <stdio.h>

int	mouse_hook(int keycode, int x, int y, t_xdata *xdata)
{
	if (xdata && x && y && (keycode == 4 || keycode == 5))
	{
		if (keycode == 4)
			xdata->sf = (xdata->sf - xdata->sf * 0.05);
		if (keycode == 5)
			xdata->sf = (xdata->sf + xdata->sf * 0.05);
		get_fractal(xdata);
	}
	return (0);
}

int	key_hook(int keycode, t_xdata *xdata)
{
	if (keycode == 65362)
		xdata->move_y += xdata->sf / 10;
	else if (keycode == 65363)
		xdata->move_x += xdata->sf / 10;
	else if (keycode == 65364)
		xdata->move_y -= xdata->sf / 10;
	else if (keycode == 65361)
		xdata->move_x -= xdata->sf / 10;
	else if (keycode == 65307)
		mlx_safe_exit(xdata);
	else
		return (1);
	get_fractal(xdata);
	return (0);
}

void get_fractal(t_xdata *xdata)
{
	if (!ft_strncmp(xdata->arg, "mandelbrot", ft_strlen("mandelbrot")))
		get_mandelbrot(xdata);
	if (!ft_strncmp(xdata->arg, "julia", ft_strlen("julia")))
		get_julia(xdata);
}

void	init_app(char *arg)
{
	t_xdata *xdata;

	xdata = (t_xdata *) malloc (sizeof (t_xdata));
	xdata->mlx_ptr = mlx_init();
	xdata->win_ptr = mlx_new_window(xdata->mlx_ptr, SW, SH, "Fract-ol");
	xdata->arg = arg;
	xdata->sf = 2.0;
	get_fractal(xdata);
	mlx_mouse_hook(xdata->win_ptr, mouse_hook, xdata);
	mlx_key_hook(xdata->win_ptr, key_hook, xdata);
	mlx_hook(xdata->win_ptr, 17, 0L, mlx_safe_exit, xdata);
	mlx_loop(xdata->mlx_ptr);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (get_few_args_err());
	if (check_args(argv[1]))
		return (get_invalid_args_err());
	init_app(argv[1]);
}
