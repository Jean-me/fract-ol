/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:29:40 by mesasaki          #+#    #+#             */
/*   Updated: 2024/06/18 04:01:10 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pr_put_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += pr_put_unsigned(n / 10);
	count += pr_putchar((n % 10) + '0');
	return (count);
}

int	pr_putnbr(int n)
{
	int	count;

	count = 0;
	if (n >= 0)
		count += pr_put_unsigned((unsigned int)n);
	if (n < 0)
	{
		count += pr_putchar('-') + pr_put_unsigned((unsigned int)-n);
	}
	return (count);
}
