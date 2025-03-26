/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:32:49 by mesasaki          #+#    #+#             */
/*   Updated: 2024/12/21 10:45:41 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		support_printf(const char *format, va_list args);
char	*ft_strchr(const char *s, int c);
int		handle_format(const char **format, va_list args);
int		pr_putchar(char c);
int		pr_putnbr(int n);
int		pr_putstr(const char *s);
int		pr_unsbase(unsigned int n, const char *base_str);
int		pr_put_unsigned(unsigned int n);
int		pr_puthex(unsigned int n, int uppercase);
int		pr_putpointer(uintptr_t ptr);
int		pr_0x(void);
int		ft_putstr_fd(const char *s);

#endif