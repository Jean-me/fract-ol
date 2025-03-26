/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:04:02 by mesasaki          #+#    #+#             */
/*   Updated: 2025/03/26 20:28:24 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	set_data(t_data *data)
{
	data->min_re = -2.0;
	data->min_im = -2.0;
	data->max_re = 2.0;
	data->max_im = 2.0;
	data->c_re = -0.4;
	data->c_im = 0.6;
}

void	change_color(t_data *data, t_julia *julia)
{
	if (data->color_name == ICE)
		julia->color = (unsigned int)((double)0xFFFFFF * julia->norn_iter
				* julia->norn_iter * julia->norn_iter);
	if (data->color_name == ROSE)
	{
		julia->red = (unsigned int)(255 * julia->norn_iter);
		julia->green = (unsigned int)(200 * julia->norn_iter * julia->norn_iter
				* julia->norn_iter);
		julia->blue = (unsigned int)(180 * julia->norn_iter * julia->norn_iter
				* julia->norn_iter);
		julia->color = (julia->red << 16) | (julia->green << 8) | julia->blue;
	}
	if (data->color_name == JAMAICA)
	{
		julia->red = (unsigned int)(255 * julia->norn_iter + 250);
		julia->green = (unsigned int)(255 * julia->norn_iter + 240);
		julia->blue = (unsigned int)(100 * julia->norn_iter);
		julia->color = (julia->red << 16) | (julia->green << 8) | julia->blue;
	}
	my_mlx_pixel_put(data, julia->x, julia->y, julia->color);
}

void	compute_iterations(t_data *data, t_julia *set)
{
	set->iter = 0;
	while (set->iter < MAX_ITER)
	{
		set->new_z_re = data->z_re * data->z_re - data->z_im * data->z_im
			+ data->c_re;
		set->new_z_im = 2 * data->z_re * data->z_im + data->c_im;
		data->z_re = set->new_z_re;
		data->z_im = set->new_z_im;
		if (data->z_re * data->z_re + data->z_im * data->z_im > (2 * 2))
			break ;
		set->iter++;
	}
	set->norn_iter = (double)set->iter / (double)MAX_ITER;
	change_color(data, set);
}

void	draw_fractal(t_data *data, int is_julia)
{
	t_julia	set;

	set.y = 0;
	while (set.y < HEIGHT)
	{
		set.x = 0;
		while (set.x < WIDTH)
		{
			data->z_re = data->min_re + (set.x / (double)WIDTH) * (data->max_re
					- data->min_re);
			data->z_im = data->max_im - (set.y / (double)HEIGHT) * (data->max_im
					- data->min_im);
			if (is_julia != JULIA)
			{
				data->c_re = data->z_re;
				data->c_im = data->z_im;
				data->z_re = 0;
				data->z_im = 0;
			}
			compute_iterations(data, &set);
			set.x++;
		}
		set.y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
