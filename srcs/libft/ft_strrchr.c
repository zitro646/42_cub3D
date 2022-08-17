/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:10:27 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/14 15:15:55 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char		*aux1;
	unsigned long	aux2;

	aux1 = s;
	aux2 = 0;
	while (aux1[aux2] != '\0')
		aux2++;
	if (c > 127)
		c = (unsigned char)c;
	while (aux2 > 0)
	{
		if (aux1[aux2] == c)
			return (&((char *)aux1)[aux2]);
		aux2--;
	}	
	if (aux1[aux2] == c)
		return (&((char *)aux1)[aux2]);
	return (0);
}
