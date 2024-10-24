/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:31:16 by aborges           #+#    #+#             */
/*   Updated: 2024/07/24 14:31:18 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65361)
		data->move_x -= 0.1 / data->zoom;
	if (keycode == 65362)
		data->move_y -= 0.1 / data->zoom;
	if (keycode == 65363)
		data->move_x += 0.1 / data->zoom;
	if (keycode == 65364)
		data->move_y += 0.1 / data->zoom;
	draw_set(data);
	return (0);
}

int	mouse_zoom(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->zoom *= 1.1;
	else if (button == 5)
		data->zoom /= 1.1;
	draw_set(data);
	return (0);
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	draw_set(t_data *data)
{
	if (strcmp(data->set, "mandelbrot") == 0)
	{
		draw_mandelbrot(data);
	}
	else if (strcmp(data->set, "julia") == 0)
	{
		draw_julia(data);
	}
	else
	{
		perror("Conjunto não reconhecido. Use 'mandelbrot' ou 'julia'.");
		exit(1);
	}
}

double	ft_atof(const char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = +1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
