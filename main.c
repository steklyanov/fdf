/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:30:31 by mmraz             #+#    #+#             */
/*   Updated: 2019/02/02 17:50:14 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"
#include <printf.h>



int		deal_key(int key, void *param)
{
	param--;
	if (key == 53) {
		// ToDo make free all memory 
		mlx_destroy_window(g_main->mlx_ptr, g_main->win_ptr);
		exit(0);
	}
	return (0);
}



void init_fdf()
{
	g_main = ft_memalloc(sizeof(g_main));
}



int     main()
{
	void *img_ptr;
	char *data;

	init_fdf(); // Malloc all struct
	g_main->mlx_ptr = mlx_init();
	g_main->win_ptr = mlx_new_window(g_main->mlx_ptr, 500, 500, "mlx 42");

	mlx_string_put(g_main->mlx_ptr, g_main->win_ptr, 10, 10, 0xFF0080, "lol");

	// Work with IMG
	img_ptr = mlx_new_image(g_main->mlx_ptr, 100, 100);
	

	data = mlx_get_data_addr(g_main->mlx_ptr, g_main->win_ptr, 10, 100);

	// *(int *)(32 + 20 * 10 +
	// 	2* 10) = mlx_get_color_value(g_main->mlx_ptr, 0xFF0080);

//	mlx_put_image_to_window(g_main->mlx_ptr, g_main->win_ptr, img_ptr, 0, 0);

	mlx_key_hook(g_main->win_ptr, deal_key, (void*)0);
	mlx_loop(g_main->mlx_ptr);
}
