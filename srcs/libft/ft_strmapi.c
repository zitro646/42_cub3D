/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:19:05 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/11 17:58:04 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*aux1;
	int		cont;
	int		tam;

	if (s == 0 || f == 0)
		return (0);
	cont = 0;
	tam = ft_strlen((char *)s);
	aux1 = ft_calloc (sizeof(char), tam + 1);
	if (aux1 == 0)
		return (0);
	while (cont < tam)
	{
		aux1[cont] = f(cont, (char)s[cont]);
		cont++;
	}
	return (aux1);
}
