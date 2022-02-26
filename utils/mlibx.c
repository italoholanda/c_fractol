/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlibx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:14:05 by igomes-h          #+#    #+#             */
/*   Updated: 2022/02/26 18:14:07 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mlibx_handle_no_event(void *data)
{
	return (0);
}

int	mlibx_handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int mlibx_init_screen(t_data data)
{
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, SIZEX, SIZEY, "FRACT'OL");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
}

int mlibx_keep_screen(t_data data, int f_no_event, int f_input)
{
	mlx_loop_hook(data.mlx_ptr, &f_no_event, &data);
	mlx_key_hook(data.win_ptr, &f_input, &data);
	mlx_loop(data.mlx_ptr);
}
