#include "fractol.h"

int main(void)
{
	t_mlx mlx;
	t_img img;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, SW, SW, "Fractal");
	img.img = mlx_new_image(mlx.ptr, SW, SW);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);

	get_fractal(img);

	mlx_put_image_to_window(mlx.ptr, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.ptr);
}
