/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:47:58 by mesasaki          #+#    #+#             */
/*   Updated: 2025/03/26 16:58:57 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100
# define ZOOM_FACTOR 1.2
# define JULIA 1
# define MANDERBROT 2
# define ROSE 3
# define ICE 4
# define JAMAICA 5

typedef struct s_data
{
	void			*mlx;
	void			*img;
	void			*win;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				frame;

	double			c_re;
	double			c_im;
	double			z_re;
	double			z_im;

	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	int				name;
	int				color_name;

}					t_data;

typedef struct s_julia
{
	int				iter;
	double			new_z_re;
	double			new_z_im;
	unsigned int	color;
	double			norn_iter;
	unsigned int	green;
	unsigned int	blue;
	unsigned int	red;
	int				y;
	int				x;
}					t_julia;

void				my_mlx_pixel_put(t_data *data, int x, int y,
						unsigned int color);
void				before_exit(t_data *data);
int					close_window(t_data *data);
void				change_color(t_data *data, t_julia *julia);
void				compute_iterations(t_data *data, t_julia *set);
void				draw_fractal(t_data *data, int is_julia);
int					mouse_zoom(int button, int x, int y, t_data *data);
int					key_hook(int keycode, t_data *data);
int					parse_fractal(char *arg);
int					parse_color(char *arg);
int					ft_strncmp(const char *s1, const char *s2, size_t count);
size_t				ft_strlen(const char *str);
int					ft_printf(const char *format, ...);
int					support_printf(const char *format, va_list args);
char				*ft_strchr(const char *s, int c);
int					pr_putchar(char c);
int					pr_putnbr(int n);
int					pr_putstr(const char *s);
int					pr_unsbase(unsigned int n, const char *base_str);
int					pr_put_unsigned(unsigned int n);
int					pr_puthex(unsigned int n, int uppercase);
int					pr_putpointer(uintptr_t ptr);
int					pr_0x(void);
int					ft_putstr_fd(const char *s);
void				set_data(t_data *data);
int					check_argv(t_data *data, int argc, char **argv);

#endif