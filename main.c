/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:30:31 by mmraz             #+#    #+#             */
/*   Updated: 2019/02/02 19:49:31 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"
#include <stdio.h>

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
	int 	fd;
	char	*line;
	char	*map;
	t_map	map_info;
	// int		**int_map;
	// int		i;

	map_info.count_line = 0;
	map = ft_strnew(1);
	fd = 0;
	map_info.line = (int**)malloc(sizeof(int*) * 120);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			while(get_next_line(fd, &line) == 1)
			{
				map_info.line[map_info.count_line++] = ft_pridumat_name(line);
				map = ft_strjoin(ft_strjoin(map, line), "\n");
			}
		}
		//printf("%s", map);
		printf("%d", map_info.line[6][1]);
		// while (map_info.count_line > 0)
		// {
		// 	while(*map_info.line[map_info.count_line])
		// 	{
		// 		printf("trulllly");
		// 		printf("%d ", *map_info.line[map_info.count_line]);
		// 	}
		// 	map_info.count_line--;
		// }
	}
	else
	{
		write(1, "usage: ./fdf file\n", 19);
	}
	
	

	return (0);
}
