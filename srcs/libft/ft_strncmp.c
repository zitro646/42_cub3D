/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:50:31 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/16 15:56:18 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*auxs1;
	unsigned char	*auxs2;
	size_t			cont;

	auxs1 = (unsigned char *)s1;
	auxs2 = (unsigned char *)s2;
	cont = 0;
	if (n == 0)
		return (0);
	while ((cont < n))
	{
		if (auxs1[cont] != auxs2[cont])
			return (auxs1[cont] - auxs2[cont]);
		if (auxs1[cont] == 0 || auxs2[cont] == 0)
			return (auxs1[cont] - auxs2[cont]);
		cont++;
	}
	return (0);
}
