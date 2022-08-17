/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:49:59 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/17 12:44:58 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	const char		*aux1;
	unsigned long	aux2;

	aux1 = s;
	aux2 = 0;
	if (c > 127)
		c = (unsigned char)c;
	while (aux1[aux2] != '\0')
	{
		if (aux1[aux2] == c)
			return (&((char *)aux1)[aux2]);
		aux2++;
	}
	if (aux1[aux2] == c)
		return (&((char *)aux1)[aux2]);
	return (0);
}
