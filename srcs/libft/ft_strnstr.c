/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:17:45 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/14 15:15:43 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	aux3;
	unsigned long	aux4;

	aux3 = 0;
	aux4 = 0;
	if (needle[0] == '\0')
		return (((char *)haystack));
	while (haystack[aux3] != '\0' && aux3 < len)
	{
		if (haystack[aux3] == needle[aux4])
		{
			aux4 = 0;
			while ((haystack[aux3 + aux4] == needle[aux4]) && \
				(needle[aux4] != '\0') && (aux3 + aux4) < len)
				aux4++;
			if (needle[aux4] == '\0')
				return (&((char *)haystack)[aux3]);
			else
				aux4 = 0;
		}
		aux3++;
	}
	return (0);
}
