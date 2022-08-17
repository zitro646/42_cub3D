/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:12:57 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/16 15:57:28 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	countinicharstodelete(char const *s1, char const *set);
static	int	countendcharstodelete(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*aux1;
	int		ini;
	int		end;

	if (s1 == NULL || set == NULL)
		return (0);
	ini = countinicharstodelete(s1, set);
	end = countendcharstodelete(s1, set);
	aux1 = ft_calloc(sizeof(char), ft_strlen((char *)s1) - ini - end + 1);
	if (aux1 == NULL)
		return (0);
	ft_strlcpy(aux1, &s1[ini], ft_strlen((char *)s1) - end - ini + 1);
	return (aux1);
}

static	int	countinicharstodelete(char const *s1, char const *set)
{
	int	cont;
	int	abort;
	int	ini;
	int	size_s1;

	cont = 0;
	abort = 0;
	ini = 0;
	size_s1 = ft_strlen((char *)s1);
	while (cont < size_s1 && abort == 0)
	{
		if (ft_strchr(set, s1[cont]) != 0)
			ini++;
		else
			abort = 1;
		cont++;
		size_s1--;
	}
	return (ini);
}

static int	countendcharstodelete(char const *s1, char const *set)
{
	int	cont;
	int	abort;
	int	end;
	int	size_s1;

	cont = 0;
	abort = 0;
	end = 0;
	size_s1 = ft_strlen((char *)s1);
	while (cont < (size_s1 - 1) && abort == 0)
	{
		if (ft_strchr(set, s1[size_s1 - 1]) != 0)
			end++;
		else
			abort = 1;
		size_s1--;
		cont++;
	}
	return (end);
}
