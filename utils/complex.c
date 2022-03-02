#include "../fractol.h"

t_complex f_convertToComplex(double sf, long int w,	long int h)
{
	t_complex aux;
	aux.a = sf / (SIZEX / 2) * w - sf;
	aux.b = -sf / (SIZEY / 2) * h + sf;
	return aux;
}

double get_module(double x, double y)
{
	return sqrt(x * x + y * y);
}
