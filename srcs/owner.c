/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   owner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:18:11 by aborges           #+#    #+#             */
/*   Updated: 2024/07/26 18:18:14 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	owner_mandelbrot(t_data *data)
{
	int		text_x;
	int		text_y_name;
	int		text_y_julia;
	char	*name;
	char	*julia;

	name = "Nome: Armando Francisco Borges";
	julia = "Fractol: Mandelbrot";
	text_x = 10;
	text_y_name = HEIGHT - 800;
	text_y_julia = HEIGHT - 750;
	mlx_string_put(data->mlx, data->win, text_x, text_y_name, 0xFFFFFF, name);
	mlx_string_put(data->mlx, data->win, text_x, text_y_julia, 0xFFA500, julia);
}

void	owner_julia(t_data *data)
{
	t_owner_julia	info;

	info.name = "Nome: Armando Francisco Borges";
	info.julia = "Fractol: Julia";
	info.text_x = 10;
	info.text_y_name = HEIGHT - 800;
	info.text_y_julia = HEIGHT - 750;
	info.text_y_params = HEIGHT - 700;
	ft_snprintf(info.params, sizeof(info.params),
		"Valores: Re = %.2f, Im = %.2f",
		data->julia_value1, data->julia_value2);
	mlx_string_put(data->mlx, data->win, info.text_x, info.text_y_name,
		0xFFFFFF, info.name);
	mlx_string_put(data->mlx, data->win, info.text_x, info.text_y_julia,
		0xFFA500, info.julia);
	mlx_string_put(data->mlx, data->win, info.text_x, info.text_y_params,
		0xFFFFFF, info.params);
}
