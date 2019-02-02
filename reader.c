/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:28:42 by mmraz             #+#    #+#             */
/*   Updated: 2019/02/02 19:08:32 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

#include <stdlib.h>

// int		ft_ln_w(char *str, int i)
// {
// 	int count;

// 	count = 0;
// 	while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
// 	{
// 		count++;
// 		i++;
// 	}
// 	return (count);
// }

// char	**ft_split_str(char *str)
// {
// 	char	**res;
// 	int		i;
// 	int		j;
// 	int		k;

// 	i = 0;
// 	j = 0;
// 	if ((res = malloc(sizeof(int*) * (ft_nb_words(str) + 1))) == NULL)
// 		return (NULL);
// 	while (str[i])
// 	{
// 		while ((str[i] == '\t' || str[i] == ' ' || str[i] == '\n') && str[i])
// 			i++;
// 		if (str[i])
// 		{
// 			k = 0;
// 			if ((res[j] = malloc(sizeof(char) * ft_ln_w(str, i) + 1)) == NULL)
// 				return (NULL);
// 			while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n' && str[i])
// 				res[j][k++] = str[i++];
// 			res[j++][k] = '\0';
// 		}
// 	}
// 	res[j] = NULL;
// 	return (res);
// }

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
		if (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' || str[i] == '\0')
		{
			count += (sym == 1) ? 1 : 0;
			sym = 0;
			i++;
		}
	}
	return (count);
}


int         *ft_pridumat_name(char *str)
{
    int     *res;
    int     i;
    int     j;
    char    *tmp;
    int     len;

	len = 0;
    i = 0;
    j = 0;
    tmp = ft_strnew(0);
    if ((res = (int*)malloc(sizeof(int) * (count_nb_digits(str)))) == NULL)
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