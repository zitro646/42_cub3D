/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:45:43 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/16 15:55:47 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux1;
	int		auxsize;

	if (s1 == NULL || s2 == NULL)
		return (0);
	auxsize = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	aux1 = ft_calloc(sizeof(char), auxsize);
	if (aux1 == NULL)
		return (0);
	ft_strlcpy(aux1, (char *)s1, auxsize);
	ft_strlcat(aux1, (char *)s2, auxsize);
	return (aux1);
}
