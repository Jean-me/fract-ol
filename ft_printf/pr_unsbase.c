/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_unsbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:32:19 by mesasaki          #+#    #+#             */
/*   Updated: 2024/06/18 04:07:28 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pr_puthex(unsigned int n, int uppercase)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += pr_puthex(n / 16, uppercase);
	if (uppercase)
		count += pr_putchar("0123456789ABCDEF"[n % 16]);
	else
		count += pr_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	pr_unsbase(unsigned int n, const char *base_str)
{
	int	count;

	count = 0;
	if (*base_str == 'u')
		count += pr_put_unsigned(n);
	else if (*base_str == 'x')
		count += pr_puthex(n, 0);
	else if (*base_str == 'X')
		count += pr_puthex(n, 1);
	return (count);
}
