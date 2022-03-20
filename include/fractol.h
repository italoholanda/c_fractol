/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:36:20 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/20 17:17:08 by igomes-h         ###   ########.fr       */
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

typedef struct s_xdata
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		img_bpp;
	int		img_endian;
	int		img_linelen;
}	t_xdata;

typedef struct s_pos
{
	long double	a;
	long double	b;
}	t_pos;

/* MLX UTILS                                                                  */
void	mlx_draw_pixel(t_xdata *xdata, int x, int y, int color);
void	mlx_set_img(t_xdata *mlx);
void	mlx_set_win(t_xdata *xdata);

/* COMPLEX UTILS                                                              */
t_pos	get_complex_conversion(double sf, long int w, long int h);
double	get_module(double x, double y);

/* MANDELBROT / JULIA                                                         */
void	get_fractal(t_xdata img, char *arg);
int		put_julia(t_xdata img, t_pos n_complex, int cw, int ch);
int		put_mandelbrot(t_xdata img, t_pos n_complex, int cw, int ch);

/* ERROR                                                                      */
int		get_few_args_err(void);
int		get_invalid_args_err(void);

/* LIBFT                                                                      */
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);

/* COLOR                                                                      */
int		get_color(int count);

#endif
