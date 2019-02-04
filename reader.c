/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:28:42 by mmraz             #+#    #+#             */
/*   Updated: 2019/02/04 13:28:34 by mmraz            ###   ########.fr       */
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
    int     *res;
    int     i;
    int     j;
    char    *tmp;

    i = 0;
    j = 0;
    tmp = ft_strnew(0);
	map->count_col = count_nb_digits(str);
    if ((res = (int*)malloc(sizeof(int) * (map->count_col))) == NULL)
        return ;
    while (str[i])
    {
        while (str[i] != ' ' && str[i])
			tmp = ft_strncat(tmp, &str[i++], 1);
        res[j++] = ft_atoi(tmp);
		free(tmp);
		tmp = ft_strnew(0);
		while (str[i] == ' ' && str[i])
			i++;
    }
	map->line[map->count_line] = res;
	map->count_line++;
}