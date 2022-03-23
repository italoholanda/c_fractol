/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomes-h <italogholanda@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:25:18 by conquer           #+#    #+#             */
/*   Updated: 2022/03/22 22:24:30 by igomes-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	get_usage(void)
{
	int wr;

	wr = write(1, "\nFractol usage:\n", sizeof(char)*16),
	wr = write(1, "./fractol mandelbrot\n", sizeof(char)*21);
	wr = write(1, "./fractol julia\n", sizeof(char)*16);
	return (wr);
}

int	get_few_args_err(void)
{
	int wr;

	wr = write(1, "[Error]: Too few arguments\n", sizeof(char)*27),
	get_usage();
	return (wr);
}

int	get_invalid_args_err(void)
{
	int wr;

	wr = write(1, "[Error]: Invalid arguments\n", sizeof(char)*27),
	get_usage();
	return (wr);
}

int	check_args(char *arg)
{
	if (!ft_strncmp(arg, "mandelbrot", ft_strlen("mandelbrot"))
		|| !ft_strncmp(arg, "julia", ft_strlen("julia")))
	{
		return (0);
	}
	return (1);
}
