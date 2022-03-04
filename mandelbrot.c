#include "fractol.h"

int	set_mandelbrot(t_img img, int N, t_pos n_complex, int cw, int ch)
{
	int count;
	double tempx;
	t_pos aux;

	count = 0;
	aux.a = 0.0;
	aux.b = 0.0;
	while (count < N)
	{
		tempx = pow(aux.a, 2) - pow(aux.b, 2) + n_complex.a;
		aux.b = 2 * aux.a * aux.b + n_complex.b;
		aux.a = tempx;

		if (aux.a * aux.a + aux.b * aux.b > 4)
		{
			draw_pixel_img(&img, (int)cw, (int)ch, 0x00FF0000);
			break;
		}
		count++;
	}

	return 0;
}
