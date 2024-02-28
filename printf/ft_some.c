/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_some.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:48:01 by vpechinn          #+#    #+#             */
/*   Updated: 2024/02/04 15:58:56 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(va_list args)
{
	int				i;
	char			*hex;
	unsigned int	num;

	i = 0;
	hex = "0123456789abcdef";
	num = va_arg(args, unsigned int);
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

int	ft_print_bigx(unsigned int num)
{
	int				i;
	char			*hex;

	i = 0;
	hex = "0123456789ABCDEF";
	if (num >= 16)
		i += ft_print_bigx(num / 16);
	else
	{
		i += ft_print_param(hex[num]);
		return (i);
	}
	num %= 16;
	i += ft_print_param(hex[num]);
	return (i);
}
