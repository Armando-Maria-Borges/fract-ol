/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:46:39 by aborges           #+#    #+#             */
/*   Updated: 2024/05/21 16:50:10 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *list, ...);
int		ft_type_specefier(char specefier, va_list arg);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_puthex(unsigned int n, int uppercase);
int		ft_putunsigned(unsigned int n);
int		ft_putpointer(unsigned long long ptr);
void	ft_putnbr(int n, int *len);
int		ft_snprintf(char *buf, size_t size, const char *fmt, ...);

#endif
