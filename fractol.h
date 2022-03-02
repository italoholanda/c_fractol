/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:27:30 by igomes-h          #+#    #+#             */
/*   Updated: 2022/03/02 17:52:18 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <X11/keysym.h>
#include <mlx.h>
#include <math.h>

#ifndef FRACTOL_H
# define FRACTOL_H
# define MLX_ERROR 1
# define SIZEX 300
# define SIZEY 300
# define ITERATIONS 1000

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_img
{
	void *img_ptr;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_img;

typedef struct s_complex
{
	long double a;
	long double b;
} t_complex;

/*
--------------------------------------------------------------------------------
    MiniLibX Aux
--------------------------------------------------------------------------------
*/
void draw_pixel_img(t_img *img, int x, int y, int color);
void draw_pixel(t_img img, long double x, long double y);

/*
--------------------------------------------------------------------------------
    Complex Utils
--------------------------------------------------------------------------------
*/
t_complex f_convertToComplex(double sf, long int w, long int h);
double get_module(double x, double y);

/*
--------------------------------------------------------------------------------
    Main
--------------------------------------------------------------------------------
*/
int	fractol(void);



#endif
