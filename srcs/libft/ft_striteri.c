/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:59:08 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/16 15:55:35 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		cont;
	int		size;

	if (s != 0 && f != 0)
	{
		cont = 0;
		size = ft_strlen((char *)s);
		while (cont < size)
		{
			f(cont, &s[cont]);
			cont++;
		}
	}
}
