/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:37:04 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/20 19:33:47 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	get_fractal(t_xdata *xdata)
{
	int		cw;
	int		ch;
	t_pos	num_complex;

	cw = 0;
	ch = 0;
	xdata->img_ptr = mlx_new_image(xdata->mlx_ptr, SW, SH);
	xdata->img_addr = mlx_get_data_addr(xdata->img_ptr, &xdata->img_bpp,
			&xdata->img_linelen, &xdata->img_endian);
	while (ch < SW)
	{
		while (cw < SW)
		{
			num_complex = get_complex_conversion(xdata->sf, cw, ch);
			if (!ft_strncmp(xdata->arg, "mandelbrot", ft_strlen("mandelbrot")))
				put_mandelbrot(xdata, num_complex, cw, ch);
			else
				put_julia(*xdata, num_complex, cw, ch);
			cw++;
		}
		cw = 0;
		ch++;
	}
	mlx_put_image_to_window(xdata->mlx_ptr, xdata->win_ptr, xdata->img_ptr, 0, 0);
	mlx_destroy_image(xdata->mlx_ptr, xdata->img_ptr);
}
