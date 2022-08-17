/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:24:16 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/25 14:33:41 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h" 

int	check_file_borders(char **map_background, int count, int i)
{	
	int		test;

	while (map_background[0][count] != 0)
		count++;
	while (map_background[i])
	{
		test = 0;
		while (map_background[i][test] != 0)
			test++;
		if (test != count)
			return (-1);
		if (map_background[i][0] != '1' || map_background[i][count - 1] != '1')
			return (-2);
		i++;
	}
	count = 0;
	while (map_background[0][count] != '\0')
	{
		if (map_background[0][count] != '1' || \
			map_background[i - 1][count] != '1')
			return (-2);
		count++;
	}
	return (1);
}

int	check_object_numbers(char **show_map, int exit, int coin, int player)
{
	int		x;
	int		y;

	y = 0;
	while (show_map[y] != 0)
	{
		x = 0;
		while (show_map[y][x] != 0)
		{
			if (show_map[y][x] == 'C')
				coin++;
			if (show_map[y][x] == 'E')
				exit++;
			if (show_map[y][x] == 'P')
				player++;
			x++;
		}
		y++;
	}
	if (coin < 1 || exit < 1 || player != 1)
		return (-1);
	return (1);
}

int	check_strange_map(char **showmap)
{	
	int		strange;
	int		i;
	int		j;

	i = 0;
	strange = 0;
	while (showmap[i])
	{
		j = 0;
		while (showmap[i][j] != '\0')
		{
			if (showmap[i][j] != '0' && showmap[i][j] != '1' \
				&& showmap[i][j] != 'P' && showmap[i][j] != 'C' \
				&& showmap[i][j] != 'E' && showmap[i][j] != 'X')
				strange++;
			j++;
		}
		i++;
	}
	return (strange);
}

int	mapcheck(t_data_map *map)
{
	int	check_border;
	int	check_objects;
	int	check_map;

	if (map == NULL)
	{
		printf ("Error - Bad map.\n");
		return (-1);
	}
	check_border = check_file_borders((map)->showmap, 0, 0);
	check_objects = check_object_numbers(map->showmap, 0, 0, 0);
	check_map = check_strange_map((map)->showmap);
	if (check_border != 1 || check_objects != 1 || check_map != 0)
	{
		printf("Error");
		if (check_border != 1)
			printf(" - Bad Border - %i" , check_border);
		if (check_objects != 1)
			printf(" - Incorrect object number - %i ", check_objects);
		if (check_map != 0)
			printf(" - Strange declaration on map - %i ", check_map);
		printf(".\n");
		return (-2);
	}
	return (1);
}
