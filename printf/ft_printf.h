/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpechinn <vpechinn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:48:01 by vpechinn          #+#    #+#             */
/*   Updated: 2024/02/04 15:58:41 by vpechinn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *param, ...);
int		ft_print_param(char c);
int		ft_print_p(va_list args);
int		ft_print_u(va_list args);
int		ft_print_i(va_list args);
int		ft_print_c(va_list args);
int		ft_print_x(va_list args);
int		ft_print_bigx(unsigned int num);
int		ft_print_hex(unsigned long long int num);

char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned int n);

#endif
