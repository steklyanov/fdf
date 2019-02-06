/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:55:28 by mmraz             #+#    #+#             */
/*   Updated: 2019/02/05 14:27:10 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

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

#include <math.h>

t_point	rotate(t_point p)
{
	t_point		v;
	int			x;
	int			y;
	int			z;

	x = p.x;
	z = p.z;
	v.x = cos(p.y) * x + sin(p.y) * z;
	v.z = -sin(p.y) * x + cos(p.y) * z;
	y = p.y;
	z = v.z;
	v.y = cos(p.x) * y - sin(p.x) * z;
	v.z = sin(p.x) * y + cos(p.x) * z;
	v.color = p.color;
	return (v);
}

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
