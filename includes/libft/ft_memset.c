/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:54:55 by aborges           #+#    #+#             */
/*   Updated: 2024/05/14 16:54:58 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int valor, size_t n)
{
	char	*cv;
	size_t	i;

	cv = (char *)s;
	i = 0;
	while (i < n)
	{
		cv[i] = valor;
		i++;
	}
	return (s);
}