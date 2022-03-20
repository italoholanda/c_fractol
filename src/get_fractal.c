/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:37:04 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/20 17:20:57 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	get_fractal(t_xdata xdata, char *arg)
{
	int		cw;
	int		ch;
	int		sf;
	t_pos	num_complex;

	cw = 0;
	ch = 0;
	sf = 2;
	while (ch < SW)
	{
		while (cw < SW)
		{
			num_complex = get_complex_conversion(sf, cw, ch);
			if (!ft_strncmp(arg, "mandelbrot", ft_strlen("mandelbrot")))
				put_mandelbrot(xdata, num_complex, cw, ch);
			else
				put_julia(xdata, num_complex, cw, ch);
			cw++;
		}
		cw = 0;
		ch++;
	}
}
