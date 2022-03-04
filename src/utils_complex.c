/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:36:32 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/04 17:29:37 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_pos	get_complex_conversion(double sf, long int w, long int h)
{
	t_pos	tmp;

	tmp.a = sf / (SW / 2) * w - sf;
	tmp.b = -sf / (SW / 2) * h + sf;
	return (tmp);
}

double	get_module(double x, double y)
{
	return (sqrt(x * x + y * y));
}
