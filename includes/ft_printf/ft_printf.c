/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:54:20 by aborges           #+#    #+#             */
/*   Updated: 2024/05/21 16:54:26 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *value, ...)
{
	va_list	args;
	int		count_char;
	int		i;

	if (!value)
		return (-1);
	i = 0;
	count_char = 0;
	va_start (args, value);
	while (value[i])
	{
		if (value[i] == '%' && value[i + 1] != '\0')
		{
			count_char = count_char + ft_type_specefier(value[i + 1], args);
			i++;
		}
		else
		{
			count_char = count_char + ft_putchar(value[i]);
		}
		i++;
	}
	va_end(args);
	return (count_char);
}
