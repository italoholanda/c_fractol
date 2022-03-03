#include "fractol.h"

t_pos get_complex_conversion(double sf, long int w, long int h)
{
    t_pos tmp;
    tmp.a = sf / (SW / 2) * w - sf;
    tmp.b = -sf / (SW / 2) * h + sf;
    return (tmp);
}

double get_module(double x, double y)
{
    return (sqrt(x * x + y * y));
}
