/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:28:42 by mmraz             #+#    #+#             */
/*   Updated: 2019/02/06 15:41:01 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"
#include <stdlib.h>

int		count_nb_digits(char *str)
{
	int i;
	int sym;
	int count;

	i = 0;
	sym = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
		{
			i++;
			sym = 1;
		}
		if (str[i] == '\t' || str[i] == ' ')
		{
			count += (sym == 1) ? 1 : 0;
			sym = 0;
			i++;
		}
	}
	return (count + sym);
}

void         ft_pridumat_name(char *str, t_map *map)
{
    t_point     *res;
    int     i;
    int     j;
    char    *tmp;

    i = 0;
    j = 0;
    tmp = ft_strnew(0);
	map->count_col = count_nb_digits(str);
    if ((res = (t_point*)malloc(sizeof(t_point) * (map->count_col))) == NULL)
        return ;
    while (str[i])
    {
        while (str[i] != ' ' && str[i])
			tmp = ft_strncat(tmp, &str[i++], 1);
        res[j++].z = ft_atoi(tmp);
		free(tmp);
		tmp = ft_strnew(0);
		while (str[i] == ' ' && str[i])
			i++;
    }
	map->line[map->count_line] = res;
	map->count_line++;
}

void		calc_point_position(t_main *main)
{
	int		step_col;
	int		step_line;
	int		i;
	int		j;

	i = 0;
	step_col = (main->image_hight - 20) / main->map->count_col;
	step_line = (main->image_weight - 20) / main->map->count_line;
	printf("\n%d step_image_height", main->image_hight);
	printf("\n%d step_image_height", main->image_weight);
	printf("\n%d step_line", step_line);
	printf("%d step_col", step_col);
	while (i < main->map->count_line)
	{
		j = 0;
		while (j < main->map->count_col)
		{
			main->map->line[i][j].x = 20 + step_line * i;
			main->map->line[i][j].y = 20 + step_line * j;
			j++;
		}
		i++;
	}

}