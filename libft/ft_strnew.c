/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:20:12 by mmraz             #+#    #+#             */
/*   Updated: 2018/11/29 12:08:31 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnew(size_t size)
{
	char			*p;
	size_t			i;

	if ((p = malloc(size + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		p[i] = '\0';
		i++;
	}
	return (p);
}
