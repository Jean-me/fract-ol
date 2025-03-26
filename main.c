/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:13:56 by mesasaki          #+#    #+#             */
/*   Updated: 2025/03/26 19:49:05 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf/ft_printf.h"
#include "mlx.h"

void	before_exit(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);
	}
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
int	close_window(t_data *data)
{
	before_exit(data);
	exit(0);
}

int	parse_fractal(char *arg)
{
	if (ft_strncmp(arg, "Julia", ft_strlen("Julia")) == 0)
		return (JULIA);
	else if (ft_strncmp(arg, "Mandelbrot", ft_strlen("Mandelbrot")) == 0)
		return (MANDERBROT);
	return (0);
}

int	parse_color(char *arg)
{
	if (ft_strncmp(arg, "ROSE", ft_strlen("ROSE")) == 0)
		return (ROSE);
	else if (ft_strncmp(arg, "ICE", ft_strlen("ICE")) == 0)
		return (ICE);
	else if (ft_strncmp(arg, "JAMAICA", ft_strlen("JAMAICA")) == 0)
		return (JAMAICA);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data data;

	data.min_re = -2.0;
	data.min_im = -2.0;
	data.max_re = 2.0;
	data.max_im = 2.0;

	data.c_re = -0.4;
	data.c_im = 0.6; // 固定パラメータ（変更可能）
	if (argc != 3)
	{
		ft_printf("Usage: %s [Julia | Mandelbrot] [ROSE | ICE | JAMAICA]\n",
			argv[0]);
		return (1);
	}

	data.mlx = mlx_init();
	// 画面出す
	data.win = mlx_new_window(data.mlx, 800, 800, "fract-ol");
	// 画像を作成
	data.img = mlx_new_image(data.mlx, 800, 800);
	// 画像のメモリアドレスを取得
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	// //画像をウィンドウに表示
	data.name = parse_fractal(argv[1]);
	data.color_name = parse_color(argv[2]);
	if (data.name == 0 || data.color_name == 0)
	{
		ft_printf("Invalid arguments\n");
		ft_printf("Usage: %s [Julia | Mandelbrot] [ROSE | ICE | JAMAICA]\n",
			argv[0]);
		return (1);
	}

	draw_fractal(&data, data.name);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, close_window, &data);
	mlx_mouse_hook(data.win, mouse_zoom, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}