#include "fractol.h"

int	get_fractal(t_img img)
{
	int		cw;
	int		ch;
	int		sf;
	t_pos	v_whconvertToComplex;
	t_pos	n_complex;

	cw = 0;
	ch = 0;
	sf = 2;
	while (ch < SW)
	{
		while (cw < SW)
		{
			v_whconvertToComplex = get_complex_conversion(sf, cw, ch);
			n_complex.a = v_whconvertToComplex.a;
			n_complex.b = v_whconvertToComplex.b;

			set_mandelbrot(img, n_complex, cw, ch);
			cw++;
		}
		cw = 0;
		ch++;
	}

	return (0);
}
