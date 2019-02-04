/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:30:31 by mmraz             #+#    #+#             */
/*   Updated: 2019/02/04 13:26:17 by mmraz            ###   ########.fr       */
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


int		main(int argc, char **argv)
{
	int 	fd;
	char	*line;
	t_map	map;
	// int		i;
	// int 	j;
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");



	map.count_line = 0;
	map.count_col = 0;
	fd = 0;
	map.line = (int**)malloc(sizeof(int*) * 120);

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		// printf("%d", fd);
		if (fd > 0)
		{
			while(get_next_line(fd, &line) == 1)
			{
				ft_pridumat_name(line, &map);
			}
		}
		print_matrix(&map);
		draw_line(&map, 10, 10, 40, 30, mlx_ptr, win_ptr);
	}
	else
		write(1, "usage: ./fdf file\n", 19);
	mlx_loop(mlx_ptr);
	return (0);
;}

int			ft_abs(int a)
{
	return (a > 0 ? a: -a);
}

void		draw_line(t_map *map, int x1, int y1, int x2, int y2, void *mlx_ptr, void *win_ptr)
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
	mlx_pixel_put(mlx_ptr, win_ptr, x2, y2, 200);
	while(x1 != x2 || y1 != y2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 200);
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

