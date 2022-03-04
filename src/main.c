#include "../include/fractol.h"

int main(void)
{
	t_mlx	mlx;
	t_img	img;

	mlx_set_win(&mlx);
	mlx_set_img(&mlx, &img);
	get_fractal(img);
	mlx_put_image_to_window(mlx.ptr, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.ptr);
}
