/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:24:32 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/09/29 17:39:59 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	flatten_map(t_data_map	*data, char **map, int y, int i)
{
	char	**newmap;
	char	*aux;

	newmap = ft_calloc(sizeof(char *), data->height + 1);
	y = 0;
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != data->max_width)
		{
			newmap[i] = ft_strjoin(map[i], " ");
			while (ft_strlen(newmap[i]) != data->max_width)
			{
				aux = ft_strjoin(newmap[i], " ");
				free(newmap[i]);
				newmap[i] = aux;
			}
		}
		else
			newmap[i] = ft_strjoin(map[i], "");
		i++;
	}
	free_matrix(data->showmap, 0);
	data->showmap = newmap;
}

void	resize_map(t_data_map	*data, char **map, int y, int i)
{
	char	**newmap;

	while (map[i])
	{
		if (map[i][0] != '\0')
			y++;
		i++;
	}
	newmap = ft_calloc(sizeof(char *), y + 1);
	y = 0;
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '\0')
		{
			newmap[y++] = ft_strjoin(map[i], "");
		}
		i++;
	}
	data->showmap = newmap;
}

static int	size_new_str(char *oldstr, char changechar, char *newchars)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (oldstr[i])
	{
		if (oldstr[i] == changechar)
			y++;
		i++;
	}
	return ((ft_strlen(oldstr) - y) + (y * ft_strlen(newchars)));
}

char	*replace_str(char *oldstr, char changechar, char *newchars)
{
	char	*newstr;
	int		i;
	int		y;
	int		aux;

	aux = 0;
	y = 0;
	i = 0;
	newstr = ft_calloc(sizeof(char), \
		size_new_str(oldstr, changechar, newchars) + 1);
	i = 0;
	y = 0;
	while (oldstr[i])
	{
		if (oldstr[i] != changechar)
			newstr[y++] = oldstr[i];
		else
			while (newchars[aux])
				newstr[y++] = newchars[aux++];
		aux = 0;
		i++;
	}
	return (newstr);
}

void	switch_chars_on_matrix(char	**map, char change, char *newchar)
{
	int		i;
	char	*aux;

	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], change) != NULL)
		{
			aux = replace_str(map[i], change, newchar);
			free (map[i]);
			map[i] = aux;
		}
		i++;
	}
}
