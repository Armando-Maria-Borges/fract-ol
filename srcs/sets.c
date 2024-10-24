/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:30:08 by aborges           #+#    #+#             */
/*   Updated: 2024/07/24 14:30:10 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	compute_mandelbrot_pixel(t_data *data, t_fractal_params *params)
{
	int	iter;
	int	color;

	params->c_re = (params->x - WIDTH / 2.0) * 4.0 / WIDTH / data->zoom
		+ data->move_x;
	params->c_im = (params->y - HEIGHT / 2.0) * 4.0 / HEIGHT / data->zoom
		+ data->move_y;
	params->z_re = params->c_re;
	params->z_im = params->c_im;
	iter = 0;
	while (iter < params->max_iter)
	{
		params->z_re2 = params->z_re * params->z_re;
		params->z_im2 = params->z_im * params->z_im;
		if (params->z_re2 + params->z_im2 > 4.0)
			break ;
		params->z_im = 2 * params->z_re * params->z_im + params->c_im;
		params->z_re = params->z_re2 - params->z_im2 + params->c_re;
		iter++;
	}
	color = calculate_color(iter, params->max_iter);
	mlx_pixel_put(data->mlx, data->win, params->x, params->y, color);
}

void	draw_mandelbrot(t_data *data)
{
	int					x;
	int					y;
	t_fractal_params	params;

	params.max_iter = 100;
	y = 0;
	while (y < HEIGHT)
	{
		params.y = y;
		x = 0;
		while (x < WIDTH)
		{
			params.x = x;
			compute_mandelbrot_pixel(data, &params);
			x++;
		}
		y++;
	}
	owner_mandelbrot(data);
}

void	compute_julia_pixel(t_data *data, t_julia_params *params, int x, int y)
{
	int	color;

	params->z_re = (x - WIDTH / 2.0) * 4.0 / WIDTH / data->zoom + data->move_x;
	params->z_im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / data->zoom
		+ data->move_y;
	params->iter = 0;
	while (params->iter < params->max_iter)
	{
		params->z_re2 = params->z_re * params->z_re;
		params->z_im2 = params->z_im * params->z_im;
		if (params->z_re2 + params->z_im2 > 4.0)
			break ;
		params->z_im = 2 * params->z_re * params->z_im + params->c_im;
		params->z_re = params->z_re2 - params->z_im2 + params->c_re;
		params->iter++;
	}
	color = get_julia_color(params);
	mlx_pixel_put(data->mlx, data->win, x, y, color);
}

void	draw_julia(t_data *data)
{
	int				x;
	int				y;
	t_julia_params	params;

	params.c_re = data->julia_value1;
	params.c_im = data->julia_value2;
	params.color_inside = 0xD3D3D3;
	params.color_start = 0xFFD700;
	params.color_end = 0x800080;
	params.color_outside = 0x000000;
	params.max_iter = 100;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			compute_julia_pixel(data, &params, x, y);
			x++;
		}
		y++;
	}
	owner_julia(data);
}
