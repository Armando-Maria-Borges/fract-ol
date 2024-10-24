/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:47:34 by aborges           #+#    #+#             */
/*   Updated: 2024/07/27 15:47:36 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}

static int	ft_putnbr(int n)
{
	char	buffer[11];
	int		i;
	int		len;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	len = i;
	while (--i >= 0)
		ft_putchar(buffer[i]);
	return (len);
}

int	ft_vsnprintf(char *buf, size_t size, const char *fmt, va_list args)
{
	size_t	i;

	i = 0;
	while (*fmt && i < size - 1)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 'd')
				i += ft_putnbr(va_arg(args, int));
			else if (*fmt == 's')
				i += ft_putstr(va_arg(args, char *));
			fmt++;
		}
		else
		{
			buf[i++] = *fmt++;
		}
	}
	buf[i] = '\0';
	return (i);
}

int	ft_snprintf(char *buf, size_t size, const char *fmt, ...)
{
	va_list	args;
	int		len;

	va_start(args, fmt);
	len = ft_vsnprintf(buf, size, fmt, args);
	va_end(args);
	return (len);
}
