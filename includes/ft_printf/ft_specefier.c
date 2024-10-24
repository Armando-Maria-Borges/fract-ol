/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_specefier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:13:20 by aborges           #+#    #+#             */
/*   Updated: 2024/05/22 12:13:23 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_type_specefier(const char value, va_list arg)
{
	int	len;

	len = 0;
	if (value == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (value == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (value == 'x')
		return (ft_puthex(va_arg(arg, unsigned int), 0));
	else if (value == 'X')
		return (ft_puthex(va_arg(arg, unsigned int), 1));
	else if (value == 'u')
		return (ft_putunsigned(va_arg(arg, unsigned int)));
	else if (value == 'p')
		return (ft_putpointer(va_arg(arg, unsigned long long)));
	else if (value == '%')
		return (ft_putchar('%'));
	else if (value == 'd' || value == 'i')
	{
		ft_putnbr((long)(va_arg(arg, int)), &len);
		return (len);
	}
	return (0);
}
