/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:10:53 by mmraz             #+#    #+#             */
/*   Updated: 2018/12/07 12:20:06 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c_arr1;
	unsigned char	*c_arr2;
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	c_arr1 = (unsigned char*)s1;
	c_arr2 = (unsigned char*)s2;
	while (*c_arr1 == *c_arr2 && ++i < n)
	{
		c_arr1++;
		c_arr2++;
	}
	return ((int)*c_arr1 - *c_arr2);
}
