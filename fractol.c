/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 18:39:41 by igomes-h          #+#    #+#             */
/*   Updated: 2022/02/26 18:52:04 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_data	data;

	mlibx_init_screen(data);
	mlibx_keep_screen(data, &mlibx_handle_no_event, &mlibx_handle_input);
}
