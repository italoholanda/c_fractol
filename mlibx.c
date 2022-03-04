#include "fractol.h"

void	mlx_set_win(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, SW, SW, "Fractal");
}

void mlx_set_img(t_mlx *mlx, t_img *img)
{
	img->img = mlx_new_image(mlx->ptr, SW, SW);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
}

void draw_pixel_img(t_img *img, int x, int y, int color)
{
	char *dst;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
