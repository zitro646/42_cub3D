/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapreader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 08:31:10 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/08/19 16:17:17 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h" 

char	**create_showmap(char *str_dir, int y_max)
{
	int			fd;
	int			i;
	int			j;
	char		**show_map;

	i = 0;
	show_map = ft_calloc(sizeof(char *), y_max + 1);
	//printf("%s\n",str_dir);
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

// t_list	**create_playerlist(t_list **player, char **show_map, int y_max)
// {
// 	int		y;
// 	int		x;

// 	y = 0;
// 	x = 0;
// 	player = ft_calloc(sizeof(t_list *), 1);
// 	while (y < y_max)
// 	{
// 		while (show_map[y][x] != '\0')
// 		{
// 			if (show_map[y][x] == 'P')
// 			{
// 				ft_lstadd_back(player, ft_lstnew(show_map[y][x], x, y));
// 			}
// 			x++;
// 		}
// 		y++;
// 		x = 0;
// 	}
// 	return (player);
// }

// t_list	**create_enemylist(t_list **enemy, char **showmap)
// {
// 	int		y;
// 	int		x;

// 	y = 0;
// 	x = 0;
// 	enemy = ft_calloc(sizeof(t_list *), 1);
// 	while (showmap[y])
// 	{
// 		while (showmap[y][x] != '\0')
// 		{
// 			if (showmap[y][x] == 'X')
// 			{
// 				ft_lstadd_back(enemy, \
// 					ft_lstnew(showmap[y][x], x, y));
// 			}
// 			x++;
// 		}
// 		y++;
// 		x = 0;
// 	}
// 	return (enemy);
// }

void see_map(t_data_map *map)
{
	int	y;

	y = 0;
	printf ("Height (%i) --> 0 - %i \n", map->height, (map->height - 1));
	while (y < map->height)
		printf ("%s\n",map->showmap[y++]);
}

t_data_map	*mapreader(char *str_dir)
{
	t_data_map	*map;

	if (get_file_height(str_dir) < 2)
		return (0);
	map = ft_calloc(sizeof(t_data_map), 1);
	map->height = get_file_height(str_dir);
	map->showmap = create_showmap(str_dir, map->height);
	// map->player = create_playerlist(map->player, map->showmap, map->height);
	// map->enemy = create_enemylist(map->enemy, map->showmap);
	map->counter_moves = 0;
	see_map(map);
	return (map);
}
