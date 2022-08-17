/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:12:27 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/16 15:54:10 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*aux1;
	unsigned char		*aux2;
	unsigned long		aux3;

	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	aux3 = 0;
	while (aux3 < n)
	{
		if (aux1[aux3] != aux2[aux3])
			return (aux1[aux3] - aux2[aux3]);
		aux3++;
	}
	if (aux3 == n)
		return (0);
	return (aux1[aux3] - aux2[aux3]);
}
