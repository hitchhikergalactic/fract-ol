/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <osredond@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:21:22 by osredond          #+#    #+#             */
/*   Updated: 2023/12/30 22:18:00 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int	exit_program(t_fractol *fractol)
{
	mlx_destroy_image(fractol->ptr_mlx, fractol->image.img_ptr);
	mlx_destroy_window(fractol->ptr_mlx, fractol->open_w);
	mlx_destroy_display(fractol->ptr_mlx);
	free(fractol->ptr_mlx);
	exit(EXIT_SUCCESS);
}

static	int	handle_key_press(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ESC)
		exit_program(fractol);
	else if (keycode == KEY_UP)
		fractol->move_y -= 0.5 * (1 / fractol->zoom);
	else if (keycode == KEY_DOWN)
		fractol->move_y += 0.5 * (1 / fractol->zoom);
	else if (keycode == KEY_LEFT)
		fractol->move_x += 0.5 * (1 / fractol->zoom);
	else if (keycode == KEY_RIGHT)
		fractol->move_x -= 0.5 * (1 / fractol->zoom);
	else if (keycode == KEY_PLUS)
		fractol->iterations += 10;
	else if (keycode == KEY_MINUS)
		fractol->iterations -= 10;
	else if (keycode == KEY_SPACE)
	{
		if (fractol->color == NEON_RED)
			fractol->color = NEON_GREEN;
		else if (fractol->color == NEON_GREEN)
			fractol->color = BLACK;
		else
			fractol->color = NEON_RED;
	}
	rendering_fractol(fractol);
	return (0);
}

static	int	handle_mouse_event(int keycode, int x, int y, t_fractol *fractol)
{
	double	i;
	double	real;

	real = x / WIDTH;
	i = y / HEIGHT;
	if (keycode == MOUSE_UP)
		zoom_in(fractol, real, i);
	else if (keycode == MOUSE_DOWN)
		zoom_out(fractol, real, i);
	rendering_fractol(fractol);
	return (0);
}

void	initialize_event_hooks(t_fractol *fractol)
{
	mlx_key_hook(fractol->open_w, handle_key_press, fractol);
	mlx_mouse_hook(fractol->open_w, handle_mouse_event, fractol);
	mlx_hook(fractol->open_w, 17, 0L, exit_program, fractol);
}
