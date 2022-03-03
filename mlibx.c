#include "fractol.h"

void draw_pixel_img(t_img *img, int x, int y, int color)
{
	char *dst;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
