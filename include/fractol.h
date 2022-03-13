/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:36:20 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/13 18:04:18 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# define FRACTOL_H
# define FRACTOL_RECURSION 50
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

/* MANDELBROT / JULIA                                                         */
void	get_fractal(t_img img, char *arg);
int		put_julia(t_img img, t_pos n_complex, int cw, int ch);
int		put_mandelbrot(t_img img, t_pos n_complex, int cw, int ch);

/* ERROR                                                                      */
int		get_few_args_err(void);
int		get_invalid_args_err(void);

/* LIBFT                                                                      */
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);

/* COLOR                                                                      */
int		get_color(int count);

#endif
