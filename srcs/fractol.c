/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:30:50 by aborges           #+#    #+#             */
/*   Updated: 2024/07/24 14:39:59 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/Xlib.h>

int	initialize_data(int argc, char **argv, t_data *data)
{
	data->set = argv[1];
	data->zoom = 1;
	data->move_x = 0;
	data->move_y = 0;
	if (ft_strcmp(data->set, "julia") == 0)
	{
		if (argc != 4)
		{
			perror("Forma de execução: julia <real> <imaginario>");
			return (1);
		}
		if (!ft_very_digit(argv[2]) || !ft_very_digit(argv[3]))
		{
			perror("Forma de execução: julia n1 n2");
			exit(1);
		}
		data->julia_value1 = ft_atof(argv[2]);
		data->julia_value2 = ft_atof(argv[3]);
	}
	else if (ft_strcmp(data->set, "mandelbrot") != 0)
	{
		perror("Apenas conjunto 'Mandelbrot' ou 'Julia'.");
		return (1);
	}
	return (0);
}

int	initialize_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		perror("Erro de inicialização da mlx");
		return (1);
	}
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol ABORGES");
	if (data->win == NULL)
	{
		perror("Erro ao abrir janela");
		return (1);
	}
	return (0);
}

void	setup_hooks(t_data *data)
{
	mlx_hook(data->win, 17, 0L, close_window, NULL);
	mlx_hook(data->win, 2, 1L, key_press, data);
	mlx_mouse_hook(data->win, mouse_zoom, data);
}

void	cleanup(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
	{
		perror("Escolha um conjunto: mandelbrot ou julia <real> <imaginario>");
		return (1);
	}
	if (initialize_data(argc, argv, &data) != 0)
		return (1);
	if (initialize_mlx(&data) != 0)
		return (1);
	setup_hooks(&data);
	draw_set(&data);
	mlx_loop(data.mlx);
	cleanup(&data);
	return (0);
}
