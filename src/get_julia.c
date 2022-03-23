/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:29:17 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/22 22:45:28 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	put_julia(t_xdata *xdata, t_pos num_complex, int w, int h)
{
	t_pos	aux;
	double	c_re;
	double	c_im;
	int		i;

	c_re = -0.7;
	c_im = 0.27015;
	i = 0;
	while (i < FRACTOL_RECURSION)
	{
		aux.a = num_complex.a;
		aux.b = num_complex.b;
		num_complex.a = aux.a * aux.a - aux.b * aux.b + c_re;
		num_complex.b = 2 * aux.a * aux.b + c_im;
		num_complex = move_screen(num_complex, xdata);
		if (num_complex.a * num_complex.a + num_complex.b * num_complex.b > 4)
		{
			mlx_draw_pixel(xdata, w, h, get_color(i));
			break ;
		}
		i++;
	}
}

void	get_julia(t_xdata *xdata)
{
	t_pos	num_complex;
	int		h;
	int		w;

	xdata->img_ptr = mlx_new_image(xdata->mlx_ptr, SW, SH);
	xdata->img_addr = mlx_get_data_addr(xdata->img_ptr, &xdata->img_bpp,
			&xdata->img_linelen, &xdata->img_endian);
	h = 0;
	while (h < SW)
	{
		w = 0;
		while (w < SW)
		{
			num_complex = get_complex_conversion(xdata->sf, w, h);
			put_julia(xdata, num_complex, w, h);
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(xdata->mlx_ptr, xdata->win_ptr,
		xdata->img_ptr, 0, 0);
	mlx_destroy_image(xdata->mlx_ptr, xdata->img_ptr);
}
