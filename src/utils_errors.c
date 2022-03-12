/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:25:18 by conquer           #+#    #+#             */
/*   Updated: 2022/03/12 16:21:11 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	get_usage(void)
{
	printf("Fractol usage:\n"),
	printf("./fractol mandelbrot\n");
	printf("./fractol julia\n");
}

int	get_few_args_err(void)
{
	printf("[Error]: Too few arguments\n");
	get_usage();
	return (1);
}

int	get_invalid_args_err(void)
{
	printf("[Error]: Invalid arguments\n");
	get_usage();
	return (1);
}
