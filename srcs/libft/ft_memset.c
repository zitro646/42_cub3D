/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:14:08 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/12/09 12:14:11 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t size)
{
	char			*aux1;
	unsigned long	aux2;

	aux1 = str;
	aux2 = 0;
	while ((aux2 < size))
	{
		*aux1 = (unsigned char)c;
		aux2++;
		aux1++;
	}
	return (str);
}
