/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlibx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:12:30 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/22 22:43:35 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdlib.h>

t_pos	move_screen(t_pos aux, t_xdata *xdata)
{
	if (xdata->move_x)
		aux.a += xdata->move_x;
	if (xdata->move_y)
		aux.b += xdata->move_y;
	return (aux);
}

int	mlx_safe_exit(t_xdata *xdata)
{
	mlx_destroy_window(xdata->mlx_ptr, xdata->win_ptr);
	mlx_destroy_display(xdata->mlx_ptr);
	free(xdata->win_ptr);
	free(xdata->mlx_ptr);
	exit (0);
}

void	mlx_draw_pixel(t_xdata *xdata, int x, int y, int color)
{
	char	*dst;

	dst = xdata->img_addr + (y * xdata->img_linelen + x * (xdata->img_bpp / 8));
	*(unsigned int *)dst = color;
}
