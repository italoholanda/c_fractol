/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mandelbrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:40:52 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/20 19:23:01 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	put_mandelbrot(t_xdata *xdata, t_pos n_complex, int cw, int ch)
{
	double	tempx;
	t_pos	aux;
	int		count;

	count = 0;
	aux.a = 0.0;
	aux.b = 0.0;
	while (count < (int)FRACTOL_RECURSION)
	{
		tempx = pow(aux.a, 2) - pow(aux.b, 2) + n_complex.a;
		aux.b = 2 * aux.a * aux.b + n_complex.b;
		aux.a = tempx;
		if (aux.a * aux.a + aux.b * aux.b > 4)
		{
			mlx_draw_pixel(xdata, (int)cw, (int)ch, get_color(count));
			break ;
		}
		mlx_draw_pixel(xdata, (int)cw, (int)ch, 0x000000);
		count++;
	}
	return (0);
}
