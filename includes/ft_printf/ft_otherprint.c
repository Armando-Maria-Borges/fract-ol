/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otherprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:06:08 by aborges           #+#    #+#             */
/*   Updated: 2024/05/22 18:06:13 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex(unsigned int n, int uppercase)
{
	int		count;
	char	*base;

	count = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex(n / 16, uppercase);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putpointer(unsigned long long ptr)
{
	char	buffer[16];
	char	*hex_digits;
	int		count;
	int		i;

	count = 0;
	if (!ptr)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	else
	{
		count += ft_putstr("0x");
		hex_digits = "0123456789abcdef";
		i = 0;
		while (ptr > 0)
		{
			buffer[i++] = hex_digits[ptr % 16];
			ptr /= 16;
		}
		while (i > 0)
			count += ft_putchar(buffer[--i]);
	}
	return (count);
}
