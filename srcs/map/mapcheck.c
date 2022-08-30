/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:24:16 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/08/30 15:57:27 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h" 

int	check_good_sorroundings(t_data_map *data, int x, int y, char *good_chars)
{
	if (x != 0 && data->showmap[y][x + 1] != '\0')
	{
		if (!ft_strchr(good_chars, data->showmap[y][x - 1]))
			return (0);
		if (!ft_strchr(good_chars, data->showmap[y][x + 1]))
			return (0);
	}
	else
		return (0);
	if ((y != 0) && (y != (data->height - 1)) && \
	(ft_strlen(data->showmap[y - 1]) + 1) > x && \
	(ft_strlen(data->showmap[y + 1]) + 1) > x)
	{
		if (!ft_strchr(good_chars, data->showmap[y - 1][x]))
			return (0);
		if (!ft_strchr(good_chars, data->showmap[y + 1][x]))
			return (0);
	}
	else
		return (0);
	return (1);
}

int	check_floors(t_data_map *data, int count, char *aceptable_chars)
{	
	int		y;
	int		x;

	count = 0;
	x = 0;
	y = 0;
	while (data->showmap[y] != '\0')
	{
		while (data->showmap[y][x])
		{
			if (data->showmap[y][x] == '0')
			{
				if (!check_good_sorroundings(data, x, y, aceptable_chars))
				{
					return (0);
				}
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (1);
}

int	check_player_on_map(t_data_map *data, char *player_type)
{
	int	player_count;
	int	y;
	int	i;

	player_count = 0;
	i = 0;
	y = 0;
	while (data->showmap[i])
	{
		while (data->showmap[i][y])
		{
			if (ft_strchr(player_type, data->showmap[i][y]) != NULL)
				player_count++;
			y++;
		}
		y = 0;
		i++;
	}
	if (player_count != 1)
		return (0);
	return (1);
}

int	check_paths(t_data_map *data)
{
	if (!data->_east_texture_path)
		return (0);
	if (!data->_north_texture_path)
		return (0);
	if (!data->_south_texture_path)
		return (0);
	if (!data->_west_texture_path)
		return (0);
	if (!data->_roof_colour_path)
		return (0);
	if (!data->_floor_colour_path)
		return (0);
	return (1);
}

int	mapcheck(t_data_map *data)
{
	int		_floors;
	int		_player;
	int		_path;

	if (data == NULL)
		return (0);
	_floors = check_floors(data, 0, "01NSWE");
	_player = check_player_on_map(data, "NSWE");
	_path = check_paths(data);
	if (_floors && _player && _path)
		return (1);
	else
	{
		printf("Error ");
		if (!_floors)
			printf("- Bad Enclosure ");
		if (!_player)
			printf("- Wrong Player Count ");
		if (!_path)
			printf("- No paths for textures ");
		printf("\n");
	}
	return (0);
}
