
#include "../include/fractol.h"

// int	put_julia(t_xdata *xdata, t_pos n_complex, int cw, int ch)
// {
// 	double	tempx;
// 	t_pos	aux;
// 	int		count;

// 	count = 0;
// 	aux.a = 0.0;
// 	aux.b = 0.0;
// 	while (count < (int)FRACTOL_RECURSION)
// 	{
// 		tempx = pow(aux.a, 2) - pow(aux.b, 2) + n_complex.a;
// 		aux.b = 2 * aux.a * aux.b + n_complex.b;
// 		aux.a = tempx;
// 		aux = move_screen(aux, xdata);
// 		if (aux.a * aux.a + aux.b * aux.b > 4)
// 		{
// 			mlx_draw_pixel(xdata, (int)cw, (int)ch, get_color(count));
// 			break ;
// 		}
// 		mlx_draw_pixel(xdata, (int)cw, (int)ch, 0x000000);
// 		count++;
// 	}
// 	return (0);
// }

// void	get_julia(t_xdata *xdata)
// {
// 	int		cw;
// 	int		ch;
// 	t_pos	num_complex;

// 	cw = 0;
// 	ch = 0;
// 	xdata->img_ptr = mlx_new_image(xdata->mlx_ptr, SW, SH);
// 	xdata->img_addr = mlx_get_data_addr(xdata->img_ptr, &xdata->img_bpp,
// 			&xdata->img_linelen, &xdata->img_endian);
// 	while (ch < SW)
// 	{
// 		while (cw < SW)
// 		{
// 			num_complex = get_complex_conversion(xdata->sf, cw, ch);
// 			put_julia(xdata, num_complex, cw, ch);
// 			cw++;
// 		}
// 		cw = 0;
// 		ch++;
// 	}
// 	mlx_put_image_to_window(xdata->mlx_ptr, xdata->win_ptr, xdata->img_ptr, 0, 0);
// 	mlx_destroy_image(xdata->mlx_ptr, xdata->img_ptr);
// }

void put_julia(t_xdata *xdata, t_pos num_complex, int w, int h)
{
	t_pos aux;
	int	i;
	double c_re = -0.7;
	double c_im = 0.27015;

	i = 0;
	while (i < FRACTOL_RECURSION)
	{

		aux.a = num_complex.a;
		aux.b = num_complex.b;
		num_complex.a = aux.a * aux.a - aux.b * aux.b + c_re;
		num_complex.b = 2 * aux.a * aux.b + c_im;
		num_complex = move_screen(num_complex, xdata);
		if (num_complex.a * num_complex.a + num_complex.b * num_complex.b > 4)
		{
			mlx_draw_pixel(xdata, w, h, get_color(i));
			break;
		}
		i++;
	}
}

void get_julia(t_xdata *xdata)
{
	t_pos num_complex;
	int h;
	int w;

	xdata->img_ptr = mlx_new_image(xdata->mlx_ptr, SW, SH);
	xdata->img_addr = mlx_get_data_addr(xdata->img_ptr, &xdata->img_bpp,
										&xdata->img_linelen, &xdata->img_endian);
	h = 0;
	while (h < SW)
	{
		w = 0;
		while (w < SW)
		{
			num_complex = get_complex_conversion(xdata->sf, w, h);
			put_julia(xdata, num_complex, w, h);
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(xdata->mlx_ptr, xdata->win_ptr, xdata->img_ptr, 0, 0);
}
