/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:36:45 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/22 19:12:36 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdlib.h>
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

int	get_movement(t_xdata *xdata, int x, int y)
{
	printf("\n");
	printf("%f|%i\n", xdata->move_x, SH - x);
	printf("%f|%i\n", xdata->move_y, SW - y);
	return 0;
}

int	mouse_hook(int keycode, int x, int y, t_xdata *xdata)
{
	if (xdata && x && y && (keycode == 4 || keycode == 5))
	{
		if (keycode == 4)
		{
			xdata->sf = (xdata->sf - xdata->sf * 0.05);
		}
		if (keycode == 5)
		{
			xdata->sf = (xdata->sf + xdata->sf * 0.05);
		}
		printf("\nPOSITION:\n");
		printf("X->%i\nY->%i\n", x, y);
		printf("\nZOOM LEVEL:\n");
		printf("%f\n",((1 / xdata->sf) * 100));
		get_fractal(xdata);
	}
	return (0);
}

int	key_hook(int keycode, t_xdata *xdata)
{
	if (keycode == 65362)
		xdata->move_y += xdata->sf / 10;
	if (keycode == 65363)
		xdata->move_x += xdata->sf / 10;
	if (keycode == 65364)
		xdata->move_y -= xdata->sf / 10;
	if (keycode == 65361)
		xdata->move_x -= xdata->sf / 10;
	get_fractal(xdata);
	return (0);
}

void	init_frac(char *arg)
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
	mlx_loop(xdata->mlx_ptr);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (get_few_args_err());
	if (check_args(argv[1]))
		return (get_invalid_args_err());
	init_frac(argv[1]);
}
