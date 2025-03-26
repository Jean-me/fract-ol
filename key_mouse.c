/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:13:56 by mesasaki          #+#    #+#             */
/*   Updated: 2025/03/26 20:19:29 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int	mouse_zoom(int button, int x, int y, t_data *data)
{
	double	zoom;
	double	mouse_re;
	double	mouse_im;

	if (button == 4 || button == 5)
	{
		if (button == 4)
			zoom = 1.0 / ZOOM_FACTOR;
		else
			zoom = ZOOM_FACTOR;
		mouse_re = data->min_re + (x / (double)WIDTH) * (data->max_re
				- data->min_re);
		mouse_im = data->max_im - (y / (double)HEIGHT) * (data->max_im
				- data->min_im);
		data->min_re = mouse_re + (data->min_re - mouse_re) * zoom;
		data->max_re = mouse_re + (data->max_re - mouse_re) * zoom;
		data->min_im = mouse_im + (data->min_im - mouse_im) * zoom;
		data->max_im = mouse_im + (data->max_im - mouse_im) * zoom;
		draw_fractal(data, data->name);
	}
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	double	step;

	if (keycode == 65307)
	{
		before_exit(data);
		exit(0);
	}
	if (data->name != JULIA)
		return (0);
	step = 0.05;
	if (keycode == 119)
		data->c_im += step;
	else if (keycode == 115)
		data->c_im -= step;
	else if (keycode == 97)
		data->c_re -= step;
	else if (keycode == 100)
		data->c_re += step;
	draw_fractal(data, data->name);
	return (0);
}
