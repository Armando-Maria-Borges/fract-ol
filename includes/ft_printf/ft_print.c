/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:02:55 by aborges           #+#    #+#             */
/*   Updated: 2024/05/21 18:03:57 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		*len += ft_putchar('-');
		*len += ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		*len += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10, len);
	}
	*len += ft_putchar(n % 10 + '0');
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		len += ft_putstr("(null)");
		return (len);
	}
	while (str[len] != '\0')
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}
