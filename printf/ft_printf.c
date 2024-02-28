/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:27:26 by vpechinn          #+#    #+#             */
/*   Updated: 2024/02/04 15:57:44 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_param(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(va_list args)
{
	int		i;
	char	*str;

	i = 0;
	str = va_arg(args, char *);
	if (str == NULL)
	{
		i = ft_printf("(null)");
	}
	else if (str[0] == 0)
		return (-1);
	else
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (i);
}

int	ft_check_type(va_list args, char param)
{
	int	len;

	len = 0;
	if (param == '%')
		len = ft_print_param(param);
	else if (param == 's')
		len = ft_print_str(args);
	else if (param == 'c')
		len = ft_print_c(args);
	else if (param == 'd' || param == 'i')
		len = ft_print_i(args);
	else if (param == 'u')
		len = ft_print_u(args);
	else if (param == 'p')
		len = ft_print_p(args);
	else if (param == 'x')
		len = ft_print_x(args);
	else if (param == 'X')
		len = ft_print_bigx(va_arg(args, unsigned int));
	return (len);
}

int	ft_check_percent(va_list args, const char *param)
{
	int	len;
	int	i;
	int	post_len;

	i = 0;
	len = 0;
	while (param[i])
	{
		post_len = 0;
		if (param[i] == '%' && param[i + 1])
			post_len = ft_check_type(args, param[i + 1]);
		else
			len += ft_print_param(param[i]);
		if (post_len)
			i++;
		if (post_len == -1)
			post_len = 0;
		i++;
		len += post_len;
	}
	return (len);
}

int	ft_printf(const char *param, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, param);
	len = ft_check_percent(args, param);
	va_end(args);
	return (len);
}

// int main()
// {	
// 	int my = printf("this is the real number: %p dasdsa", "123123");
// 	// printf("\n\n");
// 	int him = ft_printf("this is the real number: %p dasdsa", "123123");
// 	ft_printf("mylen-%d", my);
// 	printf("\n");
// 	printf("himlen-%d", him);
// }