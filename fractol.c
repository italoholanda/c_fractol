/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:39:41 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/02 17:42:56 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int fractol(void)
{
	t_mlx mlx;
	t_img img;
	t_complex v_complex;
	t_complex n_complex;
	t_complex a_complex;
	double x_tmp;
	int h_cnt;
	int w_cnt;
	int i_cnt;
	double sf;

	h_cnt = 0;
	w_cnt = 0;
	i_cnt = 0;
	sf = 2;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SIZEX, SIZEY, "Fractal");
	img.img_ptr = mlx_new_image(mlx.mlx_ptr, SIZEX, SIZEY);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
								&img.line_length, &img.endian);
	while(h_cnt < SIZEY)
	{
		while(w_cnt < SIZEX)
		{
			a_complex.a = 0.0;
			a_complex.b = 0.0;
			v_complex = f_convertToComplex(sf, w_cnt, h_cnt);
			n_complex.a = v_complex.a;
			n_complex.b = v_complex.b;

			while(i_cnt < ITERATIONS)
			{
				x_tmp = pow(a_complex.a, 2) - pow(a_complex.b, 2) + n_complex.a;
				a_complex.b = 2 * a_complex.a * a_complex.b + n_complex.b;
				a_complex.a = x_tmp;

				if (a_complex.a * a_complex.a + a_complex.b * a_complex.b > 4)
				{
					draw_pixel(img, (int)w_cnt, (int)h_cnt);
					break;
				}
			}
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
