/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapreader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 08:31:10 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/25 15:10:16 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h" 

char	**create_map(char **archive, int y_max)
{
	int			y;
	int			x;
	char		**procesed_map;
	char		*line;

	y = 0;
	x = 0;
	procesed_map = ft_calloc(sizeof(char *), y_max + 1);
	while (y < y_max)
	{
		line = ft_strdup(archive[y]);
		while (line[x] != '\0')
		{
			if (line[x] == 'E' || line[x] == 'C' || line[x] == 'P')
				line[x] = '0';
			x++;
		}
		procesed_map[y] = line;
		y++;
		x = 0;
	}
	return (procesed_map);
}

char	**create_showmap(char *str_dir, int y_max)
{
	int			fd;
	int			i;
	int			j;
	char		**show_map;

	i = 0;
	show_map = ft_calloc(sizeof(char *), y_max + 1);
	fd = open(str_dir, O_RDONLY);
	show_map[i] = get_next_line(fd);
	i = 0;
	while (show_map[i])
	{
		j = 0;
		while (show_map[i][j] != '\0')
		{
			if (show_map[i][j] == '\n')
				show_map[i][j] = '\0';
			j++;
		}
		i++;
		show_map[i] = get_next_line(fd);
	}
	close(fd);
	return (show_map);
}

t_list	**create_playerlist(t_list **player, char **show_map, int y_max)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	player = ft_calloc(sizeof(t_list *), 1);
	while (y < y_max)
	{
		while (show_map[y][x] != '\0')
		{
			if (show_map[y][x] == 'P')
			{
				ft_lstadd_back(player, ft_lstnew(show_map[y][x], x, y));
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (player);
}

t_list	**create_enemylist(t_list **enemy, char **showmap)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	enemy = ft_calloc(sizeof(t_list *), 1);
	while (showmap[y])
	{
		while (showmap[y][x] != '\0')
		{
			if (showmap[y][x] == 'X')
			{
				ft_lstadd_back(enemy, \
					ft_lstnew(showmap[y][x], x, y));
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (enemy);
}

t_data_map	*mapreader(char *str_dir)
{
	int			height;
	t_data_map	*map;

	height = get_file_height(str_dir);
	if (height < 2)
		return (0);
	map = ft_calloc(sizeof(t_data_map), 1);
	map->showmap = create_showmap(str_dir, height);
	map->background_map = create_map(map->showmap, height);
	map->player = create_playerlist(map->player, map->showmap, height);
	map->enemy = create_enemylist(map->enemy, map->showmap);
	map->counter_moves = 0;
	return (map);
}
