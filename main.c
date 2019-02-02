/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:30:31 by mmraz             #+#    #+#             */
/*   Updated: 2019/02/02 22:56:13 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"
#include <printf.h>


static void init_fdf() 
{
	g_main = ft_memalloc(sizeof(t_main));
}

int		deal_key(int key, void *param)
{
	 (void)param;
	if (key == 53) {
		// ToDo make free all memory 
		mlx_destroy_window(g_main->mlx_ptr, g_main->win_ptr);
		exit(0);
	}
	return (0);
}



int     main()
{
	void *img_ptr;
	char *data;
	int bits_per_pixel = 8;
	int size_line = 1000;
	int endian = 0;

	init_fdf(); // Malloc all struct
	g_main->mlx_ptr = mlx_init();
	g_main->win_ptr = mlx_new_window(g_main->mlx_ptr, 1000, 1000, "mlx 42");



	// Work with IMG
	img_ptr = mlx_new_image(g_main->mlx_ptr, 1000, 1000);
	data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);


	int i = 10;
	while (i++ < 100) {
		put_point_to_image(data, 30, i, 0xFF0080 * i);
	}
	int j = 0;
	while (i++ < 200) {
		if (i % 10 == 0)
			j++;
		put_point_to_image(data, 30 + j, i, 0xFF0080 * i);
	}
	while (i++ < 300) {
		if (i % 10 == 0)
			j--;
		put_point_to_image(data, 30 + j, i, 0xFF0080 * i);
	}
	while (i++ < 400) {
		put_point_to_image(data, 30, i, 0xFF0080 * i);
	}


	mlx_put_image_to_window(g_main->mlx_ptr, g_main->win_ptr, img_ptr, 0, 0);



	mlx_string_put(g_main->mlx_ptr, g_main->win_ptr, 10, 10, 0xFF0080, "lol");
	mlx_key_hook(g_main->win_ptr, deal_key, (void*)0);
	mlx_loop(g_main->mlx_ptr);
	return (0);
}
