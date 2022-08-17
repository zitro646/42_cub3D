/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:06:15 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/16 15:55:29 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	const char		*aux1;
	char			*aux2;
	unsigned long	aux3;
	unsigned long	aux4;

	aux1 = s1;
	aux3 = ft_strlen((char *)aux1);
	aux2 = malloc((aux3 + 1) * sizeof(char));
	aux4 = 0;
	if (aux2 != NULL)
	{
		while (aux4 < aux3)
		{
			aux2[aux4] = aux1[aux4];
			aux4++;
		}
		aux2[aux4] = '\0';
		return (aux2);
	}
	else
		return (0);
}
