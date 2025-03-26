/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 20:48:51 by mesasaki          #+#    #+#             */
/*   Updated: 2025/03/26 21:15:50 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf/ft_printf.h"
#include "mlx.h"

int	check_argv(t_data *data, int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Usage: %s [Julia | Mandelbrot] [ROSE | ICE | JAMAICA]\n",
			argv[0]);
		return (1);
	}
	if (data == 0 || data->color_name == 0)
	{
		ft_printf("Invalid arguments\n");
		ft_printf("Usage: %s [Julia | Mandelbrot] [ROSE | ICE | JAMAICA]\n",
			argv[0]);
		return (1);
	}
	return (0);
}
