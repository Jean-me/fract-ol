/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:31:59 by mesasaki          #+#    #+#             */
/*   Updated: 2024/12/14 14:34:44 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pr_putpointer_recursive(uintptr_t ptr)
{
	int	count;

	count = 0;
	if (ptr >= 16)
	{
		count += pr_putpointer_recursive(ptr / 16);
	}
	count += pr_putchar("0123456789abcdef"[ptr % 16]);
	return (count);
}

int	pr_putpointer(uintptr_t ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		count += pr_putstr("(nil)");
	else
	{
		count += pr_putstr("0x");
		count += pr_putpointer_recursive(ptr);
	}
	return (count);
}
