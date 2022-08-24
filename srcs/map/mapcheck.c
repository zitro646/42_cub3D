/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:24:16 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/08/24 13:25:03 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h" 

int	check_good_sorroundings(t_data_map *map, int x, int y, char *good_chars)
{
	if (x != 0 && map->showmap[y][x + 1] != '\0')
	{
		if (!ft_strchr(good_chars, map->showmap[y][x - 1]))
			return (0);
		if (!ft_strchr(good_chars, map->showmap[y][x + 1]))
			return (0);
	}
	else
		return (0);
	if ((y != 0) && (y != (map->height - 1)) && \
	(ft_strlen(map->showmap[y - 1]) + 1) > x && \
	(ft_strlen(map->showmap[y + 1]) + 1) > x)
	{
		if (!ft_strchr(good_chars, map->showmap[y - 1][x]))
			return (0);
		if (!ft_strchr(good_chars, map->showmap[y + 1][x]))
			return (0);
	}
	else
		return (0);
	return (1);
}

int	check_floors(t_data_map *map, int count, char *aceptable_chars)
{	
	int		y;
	int		x;

	count = 0;
	x = 0;
	y = 0;
	while (map->showmap[y] != '\0')
	{
		while (map->showmap[y][x])
		{
			if (map->showmap[y][x] == '0')
				if (!check_good_sorroundings(map, x, y, aceptable_chars))
					return (0);
			x++;
		}
		y++;
		x = 0;
	}
	return (1);
}

int	mapcheck(t_data_map *map)
{
	int		_floors;
	char	*_acceptable_chars;

	if (map == NULL)
	{
		printf ("Error - no map readed.\n");
		return (-1);
	}
	_acceptable_chars = "01P";
	_floors = check_floors(map, 0, _acceptable_chars);
	if (_floors)
		return (1);
	else
		return (0);
}
