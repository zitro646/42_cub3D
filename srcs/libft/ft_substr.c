/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:15:22 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/16 15:57:33 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*makestr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux1;

	if (s == NULL)
		return (0);
	if (len <= 0 || (int)start >= (ft_strlen((char *)s) + 1))
	{
		aux1 = (char *)ft_calloc(sizeof(char), 1);
		if (aux1 == NULL)
			return (0);
		return (aux1);
	}
	else
	{
		aux1 = makestr(s, start, len);
		if (aux1 == 0)
			return (0);
		return (aux1);
	}
}

static char	*makestr(char const *s, unsigned int start, size_t len)
{	
	char	*aux1;

	if ((start + len) > (ft_strlen((char *)s) - start))
	{
		aux1 = ft_calloc(sizeof(char), ft_strlen((char *)s) - start + 1);
		if (aux1 == NULL)
			return (0);
		ft_strlcpy(aux1, &s[start], ft_strlen((char *)s) - start + 1);
	}
	else
	{
		aux1 = ft_calloc(sizeof(char), len + 1);
		if (aux1 == NULL)
			return (0);
		ft_strlcpy(aux1, &s[start], len + 1);
	}
	return (aux1);
}
