/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:28:42 by mmraz             #+#    #+#             */
/*   Updated: 2019/02/02 22:41:51 by mmraz            ###   ########.fr       */
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
int			keep_rows(int rows)
{
	static int	rows2;

	rows2 = rows2 + rows;
	return (rows2); 
}

int         *ft_pridumat_name(char *str)
{
    int     *res;
    int     i;
    int     j;
    char    *tmp;
    int     len;

    i = 0;
    j = 0;
    tmp = ft_strnew(0);
	len = keep_rows(count_nb_digits(str));
    if ((res = (int*)malloc(sizeof(int) * (len))) == NULL)
        return (0);
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
    return(res);
}