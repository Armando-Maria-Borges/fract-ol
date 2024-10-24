/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setstyle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:34:52 by aborges           #+#    #+#             */
/*   Updated: 2024/07/26 15:34:54 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	calculate_color(int iter, int max_iter)
{
	t_color_mandelbrot	colors;
	double				t;
	int					red;
	int					green;
	int					blue;

	colors.color_inside = 0xD3D3D3;
	colors.color_near_border_start = 0xFFD700;
	colors.color_near_border_end = 0x800080;
	colors.color_outside = 0x000000;
	if (iter == max_iter)
		return (colors.color_inside);
	if (iter > max_iter / 2)
	{
		t = (double)(iter - max_iter / 2) / (max_iter / 2);
		red = (1 - t) * ((colors.color_near_border_start >> 16) & 0xFF) + t
			* ((colors.color_near_border_end >> 16) & 0xFF);
		green = (1 - t) * ((colors.color_near_border_start >> 8) & 0xFF) + t
			* ((colors.color_near_border_end >> 8) & 0xFF);
		blue = (1 - t) * (colors.color_near_border_start & 0xFF) + t
			* (colors.color_near_border_end & 0xFF);
		return ((red << 16) | (green << 8) | blue);
	}
	return (colors.color_outside);
}

int	get_julia_color(t_julia_params *params)
{
	int		red;
	int		green;
	int		blue;
	double	t;

	if (params->iter == params->max_iter)
		return (params->color_inside);
	else if (params->iter > params->max_iter / 2)
	{
		t = (double)(params->iter - params->max_iter / 2) / (params->max_iter
				/ 2);
		red = (int)((1 - t) * ((params->color_start >> 16) & 0xFF) + t
				* ((params->color_end >> 16) & 0xFF));
		green = (int)((1 - t) * ((params->color_start >> 8) & 0xFF) + t
				* ((params->color_end >> 8) & 0xFF));
		blue = (int)((1 - t) * (params->color_start & 0xFF) + t
				* (params->color_end & 0xFF));
		return ((red << 16) | (green << 8) | blue);
	}
	else
		return (params->color_outside);
}
