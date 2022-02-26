#include <stdlib.h>
#include <X11/keysym.h>
#include <mlx.h>

#ifndef FRACTOL_H
# define FRACTOL_H
# define MLX_ERROR 1
# define SIZEX 300
# define SIZEY 300

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

#endif
