/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fromLibft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesasaki <mesasaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:07:21 by mesasaki          #+#    #+#             */
/*   Updated: 2025/03/26 17:00:21 by mesasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int	ft_strncmp(const char *s1, const char *s2, size_t count)
{
	size_t			i;
	unsigned char	ch1;
	unsigned char	ch2;

	i = 0;
	while ((s1[i] || s2[i]) && i < count)
	{
		ch1 = (unsigned char)s1[i];
		ch2 = (unsigned char)s2[i];
		if (ch1 != ch2)
			return (ch1 - ch2);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}