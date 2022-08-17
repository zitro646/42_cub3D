/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:34:26 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/14 15:14:38 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*aux1;

	aux1 = malloc(count * size);
	if (aux1 == NULL)
		return (0);
	ft_bzero(aux1, (count * size));
	return (aux1);
}
