/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_check_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:39:36 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/09/08 15:55:05 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

int	path_exist(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd != -1)
	{
		close (fd);
		return (1);
	}
	return (0);
}

int	colour_is_valid(char *str)
{
	char	**aux_str;
	int		num;
	int		i;
	int		tam;
	int		check;

	check = 1;
	i = 0;
	aux_str = ft_split(str, ',');
	tam = get_matrix_height(aux_str);
	while (i < tam)
	{
		num = ft_atoi(aux_str[i]);
		if (num == 0 && ft_strncmp(aux_str[i], "0", ft_strlen(aux_str[i])))
			check = 0;
		if (num < 0 || num > 255)
			check = 0;
		i++;
	}
	if (tam != 3)
		check = 0;
	free_matrix(aux_str, 0);
	return (check);
}
// int	check_value_paths(t_data_map *data)
// {
// 	char **aux;
// 	if ()
// 	return (1);
// }

int	check_paths(t_data_map *data)
{
	if (!data->_east_texture_path || !path_exist(data->_east_texture_path))
		return (0);
	if (!data->_north_texture_path || !path_exist(data->_north_texture_path))
		return (0);
	if (!data->_south_texture_path || !path_exist(data->_south_texture_path))
		return (0);
	if (!data->_west_texture_path || !path_exist(data->_west_texture_path))
		return (0);
	if (!data->_roof_colour_path)
		return (0);
	if (!data->_floor_colour_path)
		return (0);
	return (1);
}

int	check_map_no_strange_chars(char **map, char *acceptable_chars)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (map[i])
	{
		while (map[i][y])
		{
			if (!ft_strchr(acceptable_chars, map[i][y]))
				return (0);
			y++;
		}
		y = 0;
		i++;
	}
	return (1);
}

static	int	check_good_sorroundings(t_data_map *data, int x, \
									int y, char *good_chars)
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

int	check_map_closed(t_data_map *data, int count, char *aceptable_chars)
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


