/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:29:40 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/16 15:55:04 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	cont;
	int	size;

	if (s != 0)
	{
		cont = 0;
		size = ft_strlen(s);
		while (cont < size)
		{
			write (fd, &s[cont], 1);
			cont++;
		}
	}
}
