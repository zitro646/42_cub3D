/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:41:23 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/16 15:55:53 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	cont;
	unsigned int	modsize;

	cont = 0;
	while (dst[cont] != '\0' && cont <= dstsize)
		cont++;
	modsize = dstsize - cont;
	if (cont < dstsize)
		return (cont + ft_strlcpy ((dst + cont), src, modsize));
	return (ft_strlen((char *)src) + dstsize);
}
