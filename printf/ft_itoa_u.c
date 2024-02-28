/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:30:57 by vpechinn          #+#    #+#             */
/*   Updated: 2024/02/03 17:26:20 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_size_u(unsigned int nb, int i)
{
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_putnum_u(int i, unsigned int n, char *str)
{
	while (i >= 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa_u(unsigned int n)
{
	char	*str;
	int		i;

	i = 0;
	i = ft_size_u(n, i);
	str = malloc(i + 2);
	if (str == 0)
		return (0);
	str[i + 1] = '\0';
	str = ft_putnum_u(i, n, str);
	return (str);
}
