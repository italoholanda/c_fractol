/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:36:45 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/21 19:30:27 by igomes-h         ###   ########.fr       */
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


int	mouse_hook(int keycode, int x, int y, t_xdata *xdata)
{
	if (xdata && x && y && (keycode == 4 || keycode == 5))
	{
		if (keycode == 4)
		{
			xdata->sf = (xdata->sf - xdata->sf * 0.05);
			printf("-> %f \n", xdata->sf);
		}
		if (keycode == 5)
		{
			xdata->sf = (xdata->sf + xdata->sf * 0.05);
			printf("-> %f \n", xdata->sf);
		}
		get_fractal(xdata);
	}
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
