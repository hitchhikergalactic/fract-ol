/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <osredond@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 18:36:55 by osredond          #+#    #+#             */
/*   Updated: 2023/12/30 22:45:39 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_out(t_fractol	*fractol, double mouse_x, double mouse_y)
{
	fractol->zoom *= 0.9;
	fractol->move_x += mouse_x / (0.5 * WIDTH * fractol->zoom);
	fractol->move_y += mouse_y / (0.5 * HEIGHT * fractol->zoom);
}

void	zoom_in(t_fractol	*fractol, double mouse_x, double mouse_y)
{
	fractol->zoom *= 1.1;
	fractol->move_x -= mouse_x / (0.5 * WIDTH * fractol->zoom);
	fractol->move_y -= mouse_y / (0.5 * HEIGHT * fractol->zoom);
}
