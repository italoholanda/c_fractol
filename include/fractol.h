/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:36:20 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/04 17:32:03 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# include <mlx.h>
# include <math.h>

# define FRACTOL_H
# define SW 360
# define SH 360

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_pos
{
	long double	a;
	long double	b;
}	t_pos;

/* MLX UTILS                                                                  */
void	mlx_draw_pixel(t_img *img, int x, int y, int color);
void	mlx_set_img(t_mlx *mlx, t_img *img);
void	mlx_set_win(t_mlx *mlx);

/* COMPLEX UTILS                                                              */
t_pos	get_complex_conversion(double sf, long int w, long int h);
double	get_module(double x, double y);

/* MANDELBROT                                                                 */
int		get_mandelbrot(t_img img);

#endif
