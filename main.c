/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:30:31 by mmraz             #+#    #+#             */
/*   Updated: 2019/02/04 19:50:25 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"
#include <stdio.h>


void	print_matrix(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->count_line)
	{
		j = 0;
		while (j < map->count_col)
		{
			printf("%d ", map->line[i][j]);
			// printf("%d:%d ", i, j);
			j++;
		}
		i++;
		printf("\n");
	}
}

int		deal_key(int key, void *param)
{
	 (void)param;
	if (key == 53) {
		// ToDo make free all memory 
		// mlx_destroy_window(mlx_ptr, win_ptr);
		exit(0);
	}
	return (0);
}

t_main	*init_main(t_main *main)
{
	main = ft_memalloc(sizeof(t_main));
	main->mlx_ptr = mlx_init();

	main->map = ft_memalloc(sizeof(t_map));
	main->map->line = (int**)malloc(sizeof(int*) * 1200); // ToDo more num  !!!
	main->map->count_line = 0;
	main->map->count_col = 0;

	return (main);
}

void	init_screen(t_main *main)
{
		printf("%d count_line\n\n", main->map->count_line);
	//	printf("%d image_weight\n\n", main->image_weight);
	if (main->map->count_line > 300)
	{
		main->image_hight = 1000;
		main->image_weight = 1000;
	}
	else if (main->map->count_line >= 100)
	{
		main->image_hight = 700;
		main->image_weight = 700;
	}
	else
	{
		main->image_hight = 500;
		main->image_weight = 500;
	}
}


int		main(int argc, char **argv)
{
	int 	fd;
	char	*line;
	t_main	*main = 0x0;

	int bits_per_pixel = 8;
	int size_line = 1000; 
	int endian = 0;

	main = init_main(main);

	fd = 0;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			while(get_next_line(fd, &line) == 1)
				ft_pridumat_name(line, main->map);
		}
		// Iint MIAN 
		init_screen(main);
		main->win_ptr = mlx_new_window(main->mlx_ptr, main->image_hight, main->image_hight, "mlx 42");

		// Work with IMG
		main->img_ptr = mlx_new_image(main->mlx_ptr, main->image_weight, main->image_hight);
		main->data = mlx_get_data_addr(main->img_ptr, &bits_per_pixel, &size_line, &endian);
		
		draw_line(main->map, 100, 100, 130, 120, main);

		mlx_put_image_to_window(main->mlx_ptr, main->win_ptr, main->img_ptr, 0, 0);

		mlx_string_put(main->mlx_ptr, main->win_ptr, 10, 10, 0xFF0080, "lol");
		mlx_key_hook(main->win_ptr, deal_key, (void*)0);
	}
	else
		write(1, "usage: ./fdf file\n", 19);
	mlx_loop(main->mlx_ptr);

}

void    put_point_to_image(char *image_data, int x, int y, int color, t_main *main)
{
    int index;
    
    index = main->image_weight * y * 4 + x * 4;
	image_data[index + 2] = color >> 16; // RED COLOR COMPONENT
	image_data[index + 1] = (color & 0x00ff00) >> 8; // GREEN COLOR COMPONENT
}

int			ft_abs(int a)
{
	return (a > 0 ? a: -a);
}

// void		draw_map(t_map *map, char *image_data)
// {
	
// }

void		draw_line(t_map *map, int x1, int y1, int x2, int y2, t_main *main)
{
	int		delta_x;
	int		delta_y;
	int		sign_x;
	int		sign_y;
	int		error;
	int		error2;

	printf("%d\n", map->count_col);
	delta_x = ft_abs(x2 - x1);
	delta_y = ft_abs(y2 - y1);
	sign_x = x1 < x2 ? 1: -1;
	sign_y = y1 < y2 ? 1: -1;
	error = delta_x - delta_y;
	put_point_to_image(main->data, x2, y2, 0x00FFFFFF, main);
	while(x1 != x2 || y1 != y2)
	{
		put_point_to_image(main->data, x1, y1, 0x00FFFFFF, main);
		error2 = error * 2;
		if (error2 > delta_y)
		{
			error -= delta_y;
			x1 += sign_x;
		}
		if (error2 < delta_x)
		{
			error += delta_x;
			y1 += sign_y;
		}
	}

}

