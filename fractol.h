/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:27:30 by igomes-h          #+#    #+#             */
/*   Updated: 2022/02/26 19:01:51 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*
--------------------------------------------------------------------------------
    MiniLibX Aux
--------------------------------------------------------------------------------
*/
int	mlibx_handle_no_event(void *data);
int	mlibx_handle_input(int keysym, t_data *data);
int mlibx_init_screen(t_data data);
int mlibx_keep_screen(t_data data, int *f_no_event, int *f_input);

#endif
