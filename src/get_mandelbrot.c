/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mandelbrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:37:04 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/04 17:28:33 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

#define MANDELBROT_RECURSION 50

int	mandelbrot_pixel_put(t_img img, t_pos n_complex, int cw, int ch)
{
	double	tempx;
	t_pos	aux;
	int		count;

	count = 0;
	aux.a = 0.0;
	aux.b = 0.0;
	while (count < (int)MANDELBROT_RECURSION)
	{
		tempx = pow(aux.a, 2) - pow(aux.b, 2) + n_complex.a;
		aux.b = 2 * aux.a * aux.b + n_complex.b;
		aux.a = tempx;
		if (aux.a * aux.a + aux.b * aux.b > 4)
		{
			mlx_draw_pixel(&img, (int)cw, (int)ch, 0x00FFFFFF);
			break ;
		}
		mlx_draw_pixel(&img, (int)cw, (int)ch, 0x00000000);
		count++;
	}
	return (0);
}

int	get_mandelbrot(t_img img)
{
	int		cw;
	int		ch;
	int		sf;
	t_pos	tmp_complex;
	t_pos	num_complex;

	cw = 0;
	ch = 0;
	sf = 2;
	while (ch < SW)
	{
		while (cw < SW)
		{
			tmp_complex = get_complex_conversion(sf, cw, ch);
			num_complex.a = tmp_complex.a;
			num_complex.b = tmp_complex.b;
			mandelbrot_pixel_put(img, num_complex, cw, ch);
			cw++;
		}
		cw = 0;
		ch++;
	}
	return (0);
}
