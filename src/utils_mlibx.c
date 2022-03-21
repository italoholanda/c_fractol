/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlibx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:12:30 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/20 18:42:45 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdlib.h>

void	mlx_set_win(t_xdata *xdata)
{
	xdata->mlx_ptr = mlx_init();
	xdata->win_ptr = mlx_new_window(xdata->mlx_ptr, SW, SW, "Fractal");
}

void	mlx_set_img(t_xdata *xdata)
{
	xdata->img_ptr = mlx_new_image(xdata->mlx_ptr, SW, SW);
	xdata->img_addr = mlx_get_data_addr(xdata->img_ptr, &xdata->img_bpp, &xdata->img_linelen,
			&xdata->img_endian);
}

void	mlx_draw_pixel(t_xdata *xdata, int x, int y, int color)
{
	char	*dst;

	dst = xdata->img_addr + (y * xdata->img_linelen + x * (xdata->img_bpp / 8));
	*(unsigned int *)dst = color;
}
