/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlibx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:14:05 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/02 17:41:22 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void draw_pixel_img(t_img *img, int x, int y, int color)
{
	char *dst;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_pixel(t_img img, long double x, long double y)
{
	draw_pixel_img(&img, x, y, 0x00FF0000);
}
