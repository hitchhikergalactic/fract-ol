/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <osredond@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:24:35 by osredond          #+#    #+#             */
/*   Updated: 2023/12/30 22:21:30 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	julia_params(t_fractol *fractol, char **param)
{
	if (ft_atoi(*param) == 1)
	{
		fractol->julia_real = 0.285;
		fractol->julia_i = -0.01;
	}
	else if (ft_atoi(*param) == 2)
	{
		fractol->julia_real = -0.70176;
		fractol->julia_i = -0.3842;
	}
	else if (ft_atoi(*param) == 3)
	{
		fractol->julia_real = -0.755;
		fractol->julia_i = 0.15;
	}
	else if (ft_atoi(*param) == 4)
	{
		fractol->julia_real = -0.835;
		fractol->julia_i = -0.2321;
	}
	else
		perror_exit();
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc <= 3)
	{
		if (argv[1] && argv[2] && ft_strncmp(argv[1], "julia", 5) == 0)
		{
			fractol.name = argv[1];
			julia_params(&fractol, &argv[2]);
		}
		else if (argv[1] && !argv[2]
			&& ft_strncmp(argv[1], "mandelbrot", 10) == 0)
			fractol.name = argv[1];
		else if (argv[1] && !argv[2]
			&& ft_strncmp(argv[1], "multibrot", 9) == 0)
			fractol.name = argv[1];
		else
			perror_exit();
		init_fractol(&fractol);
		rendering_fractol(&fractol);
		mlx_loop(fractol.ptr_mlx);
	}
	else
		perror_exit();
	return (0);
}
