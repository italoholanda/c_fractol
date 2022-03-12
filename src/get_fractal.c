/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:37:04 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/12 16:42:59 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	get_fractal(t_img img, char *arg)
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
			if (!ft_strncmp(arg, "mandelbrot", ft_strlen("mandelbrot")))
				put_mandelbrot(img, num_complex, cw, ch);
			else
				put_julia(img, num_complex, cw, ch);
			cw++;
		}
		cw = 0;
		ch++;
	}
}
