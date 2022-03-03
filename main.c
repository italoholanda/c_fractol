#include "fractol.h"

int main(void)
{
	void *mlx;
	void *mlx_win;
	double tempx;
	double sf = 2;
	t_pos v_whconvertToComplex;
	t_pos n_complex, aux;
	t_img img;
	int N = 50;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SW, SW, "Fractal");
	img.img = mlx_new_image(mlx, SW, SW);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);

	for (int h = 0; h < SW; h++)
	{
		for (int w = 0; w < SW; w++)
		{
			aux.a = 0.0;
			aux.b = 0.0;

			v_whconvertToComplex = get_complex_conversion(sf, w, h);
			n_complex.a = v_whconvertToComplex.a;
			n_complex.b = v_whconvertToComplex.b;

			for (int i = 0; i < N; i++)
			{
				tempx = pow(aux.a, 2) - pow(aux.b, 2) + n_complex.a;
				aux.b = 2 * aux.a * aux.b + n_complex.b;
				aux.a = tempx;

				if (aux.a * aux.a + aux.b * aux.b > 4)
				{
					draw_pixel_img(&img, (int)w, (int)h, 0x00FF0000);
					break;
				}
			}
		}
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
