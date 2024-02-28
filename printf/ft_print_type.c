/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:39:24 by vpechinn          #+#    #+#             */
/*   Updated: 2024/02/04 16:08:14 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long int num)
{
	int				i;
	char			*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (num >= 16)
		i += ft_print_hex(num / 16);
	else
	{
		i += ft_print_param(hex[num]);
		return (i);
	}
	num %= 16;
	i += ft_print_param(hex[num]);
	return (i);
}

int	ft_print_c(va_list args)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_print_i(va_list args)
{
	int		i;
	int		integer;
	char	*num;

	integer = va_arg(args, int);
	num = ft_itoa(integer);
	i = 0;
	while (num[i])
	{
		write(1, &num[i], 1);
		i++;
	}
	free(num);
	return (i);
}

int	ft_print_u(va_list args)
{
	unsigned int	i;
	unsigned int	integer;
	char			*num;

	i = 0;
	integer = va_arg(args, unsigned int);
	num = ft_itoa_u(integer);
	while (num[i])
	{
		write(1, &num[i], 1);
		i++;
	}
	free(num);
	return (i);
}

int	ft_print_p(va_list args)
{
	int						i;
	unsigned long long int	integer;

	i = 0;
	integer = va_arg(args, unsigned long long int);
	i += ft_print_param('0');
	i += ft_print_param('x');
	i += ft_print_hex(integer);
	return (i);
}
