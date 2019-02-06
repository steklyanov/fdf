/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:24:38 by mmraz             #+#    #+#             */
/*   Updated: 2019/02/06 18:02:58 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void    update_points(t_main *main, t_angle angles)
{

}

void        rot_z(t_main *main)
{
    int     i;
    int     j;
    t_point *tmp;
    t_point tmp2;

    while (i < main->map->count_line)
	{
		j = 0;
		while (j < main->map->count_col)
		{
            tmp2 = main->map->line[i][j];
            tmp = &main->map->line[i][j];
            main->map->line[i][j].x = (tmp2.x * cos(0.0873)) - (tmp2.y * sin(0.0873));
            main->map->line[i][j].y = (tmp2.x * sin(0.0873)) + (tmp2.y * cos(0.0873));
			j++;
		}
		i++;
	}
}

void        rot_x(t_main *main)
{
    int     i;
    int     j;
    t_point *tmp;
    t_point tmp2;

    while (i < main->map->count_line)
	{
		j = 0;
		while (j < main->map->count_col)
		{
            tmp2 = main->map->line[i][j];
            tmp = &main->map->line[i][j];
            main->map->line[i][j].y = (tmp2.y * cos(0.0873)) - (tmp2.z * sin(0.0873));
            main->map->line[i][j].z = (tmp2.y * sin(0.0873)) + (tmp2.z * cos(0.0873));
			j++;
		}
		i++;
	}
}

void        rot_y(t_main *main)
{
    int     i;
    int     j;
    t_point *tmp;
    t_point tmp2;

    while (i < main->map->count_line)
	{
		j = 0;
		while (j < main->map->count_col)
		{
            tmp2 = main->map->line[i][j];
            tmp = &main->map->line[i][j];
            main->map->line[i][j].x = (tmp2.z * sin(0.0873)) + (tmp2.x * cos(0.0873));
            main->map->line[i][j].z = (tmp2.z * cos(0.0873)) - (tmp2.x * sin(0.0873));
			j++;
		}
		i++;
	}
}