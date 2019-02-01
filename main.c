/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:30:31 by mmraz             #+#    #+#             */
/*   Updated: 2019/02/01 11:39:25 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// int		deal_key(int key, void *param)
// {
// 	key = 0;
// 	param = param - 1;
// 	ft_putchar('X');
// 	return (0);
// }

// int     main()
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;

// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
// 	mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 200);
// 	mlx_pixel_put(mlx_ptr, win_ptr, 101, 100, 200);
// 	mlx_pixel_put(mlx_ptr, win_ptr, 100, 101, 200);
// 	mlx_pixel_put(mlx_ptr, win_ptr, 101, 101, 200);
// 	mlx_key_hook(win_ptr, deal_key, (void*)0);
// 	mlx_loop(mlx_ptr);
// }

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		
	}
	else
	{
		write(1, "usage: ./fdf file\n", 19);
	}

	return (0);
}
