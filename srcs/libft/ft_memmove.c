/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:37:01 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/16 15:54:19 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*aux1;
	char			*aux2;
	unsigned long	aux3;

	aux1 = (char *)dst;
	aux2 = (char *)src;
	aux3 = 0;
	if (aux1 < aux2)
	{
		while (aux3 < len)
		{
			aux1[aux3] = aux2[aux3];
			aux3++;
		}
	}
	else if (aux1 > aux2)
	{
		while (len-- > 0)
			aux1[len] = aux2[len];
	}
	return (aux1);
}
