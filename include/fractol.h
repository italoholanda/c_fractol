/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:36:20 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/22 22:36:27 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define FRACTOL_H
# define FRACTOL_RECURSION 100
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
	char	*arg;
	double	sf;
	double	move_x;
	double	move_y;
}	t_xdata;

typedef struct s_pos
{
	long double	a;
	long double	b;
}	t_pos;

/* MLX UTILS                                                                  */
void	mlx_draw_pixel(t_xdata *xdata, int x, int y, int color);
t_pos	move_screen(t_pos aux, t_xdata *xdata);
int		mlx_safe_exit(t_xdata *xdata);

/* COMPLEX UTILS                                                              */
t_pos	get_complex_conversion(double sf, long int w, long int h);
double	get_module(double x, double y);

/* MANDELBROT / JULIA                                                         */
void	get_fractal(t_xdata *xdata);
void	get_mandelbrot(t_xdata *xdata);
int		put_mandelbrot(t_xdata *xdata, t_pos n_complex, int cw, int ch);
void	get_julia(t_xdata *xdata);
void	put_julia(t_xdata *xdata, t_pos num_complex, int w, int h);

/* ERROR                                                                      */
int		get_few_args_err(void);
int		get_invalid_args_err(void);
int		check_args(char *arg);

/* LIBFT                                                                      */
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);

/* COLOR                                                                      */
int		get_color(int count);

#endif
