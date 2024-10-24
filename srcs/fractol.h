/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:33:13 by aborges           #+#    #+#             */
/*   Updated: 2024/07/24 14:33:15 by aborges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include "../includes/ft_printf/ft_printf.h"
# include "../includes/libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1925
# define HEIGHT 1100

typedef struct s_owner_julia
{
	char	*name;
	char	*julia;
	char	params[100];
	int		text_x;
	int		text_y_name;
	int		text_y_julia;
	int		text_y_params;
}	t_owner_julia;

typedef struct s_color_mandelbrot
{
	int	color_inside;
	int	color_near_border_start;
	int	color_near_border_end;
	int	color_outside;
}	t_color_mandelbrot;

typedef struct s_data
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*set;
	double	julia_value1;
	double	julia_value2;
	double	zoom;
	double	move_x;
	double	move_y;
}			t_data;

typedef struct s_fractal_params
{
	int		x;
	int		y;
	int		max_iter;
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
}			t_fractal_params;

typedef struct s_julia_params
{
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	z_re2;
	double	z_im2;
	int		iter;
	int		max_iter;
	int		color_inside;
	int		color_start;
	int		color_end;
	int		color_outside;
}			t_julia_params;

int			key_press(int keycode, t_data *data);
int			close_window(void *param);
int			mouse_zoom(int button, int x, int y, t_data *data);
int			calculate_color(int iter, int max_iter);
int			get_julia_color(t_julia_params *params);
int			ft_isdigit(int c);
void		draw_set(t_data *data);
void		draw_mandelbrot(t_data *data);
void		draw_julia(t_data *data);
void		draw_background(t_data *data);

void		owner_mandelbrot(t_data *data);
void		owner_julia(t_data *data);

double		ft_atof(const char *str);
int			ft_strcmp(char *s1, char *s2);

#endif
