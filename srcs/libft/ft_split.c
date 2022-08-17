/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:41:56 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/14 15:15:21 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	partscount(char const *s, char c);
static char	*word(char const *s, char c);
static void	ft_free_all(char **array, int size);
static char	**make_array(char **array, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**aux1;

	if (s == NULL)
		return (0);
	aux1 = ft_calloc(sizeof(char *), partscount(s, c) + 1);
	if (aux1 == NULL)
		return (0);
	aux1 = make_array(aux1, s, c);
	return (aux1);
}

static char	**make_array(char **array, char const *s, char c)
{
	int		cont;
	char	*aux1;

	aux1 = (char *)s;
	cont = 0;
	while (cont < partscount(s, c))
	{
		array[cont] = word((const char *)aux1, c);
		if (array[cont] == NULL)
		{
			ft_free_all(array, cont);
			return (0);
		}
		if (ft_strlen(array[cont]) != 0)
			cont++;
		else
			free(array[cont]);
		aux1 = ft_strchr(aux1, (int)c) + 1;
	}
	return (array);
}

static char	*word(const char *s, char c)
{
	char	*aux1;
	int		pos;

	if (c != '\0')
	{	
		if (ft_strchr(s, (int)c) != NULL)
			pos = ft_strlen((char *)s) - ft_strlen(ft_strchr(s, (int)c));
		else
			pos = ft_strlen((char *)s);
		aux1 = ft_calloc(sizeof(char), pos + 1);
		if (aux1 == 0)
			return (0);
		ft_strlcpy(aux1, s, (size_t)(pos + 1));
	}
	else
	{
		pos = ft_strlen((char *)s);
		aux1 = ft_calloc(sizeof(char), pos + 1);
		if (aux1 == 0)
			return (0);
		ft_strlcpy(aux1, s, (size_t)pos + 1);
	}
	return (aux1);
}

static int	partscount(char const *s, char c)
{
	char	*aux1;
	int		cont;

	cont = 0;
	aux1 = (char *)s;
	if (c == '\0')
	{
		if (ft_strlen((char *)s) > 0)
			return (1);
		return (0);
	}
	while (ft_strchr(aux1, c) != NULL)
	{
		if ((ft_strlen(aux1) - ft_strlen(ft_strchr(aux1, (int)c)) != 0))
			cont++;
		aux1 = ft_strchr(aux1, (int)c) + 1;
	}
	if (ft_strlen(aux1) > 0)
		cont++;
	return (cont);
}

static void	ft_free_all(char **array, int size)
{
	int	cont;

	cont = 0;
	while (cont <= size)
	{
		free(array[cont]);
		cont++;
	}
	free(array);
}
