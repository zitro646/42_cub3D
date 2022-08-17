/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:02:47 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/16 15:54:14 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*aux1;
	const unsigned char	*aux2;
	unsigned long		aux3;

	aux1 = dest;
	aux2 = src;
	aux3 = 0;
	if (aux1 == NULL && aux2 == NULL)
		return (0);
	while (aux3 < n)
	{
		aux1[aux3] = aux2[aux3];
		aux3++;
	}
	return (dest);
}
