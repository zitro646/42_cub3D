/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:38:08 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/08/19 17:50:01 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window/window.h"
#include <stdio.h>

void	leaks(void)
{
	system("leaks -q test");
}

void	free_all(t_data_map *data_map)
{
	int	i;

	i = 0;
	while (data_map->showmap[i])
		free(data_map->showmap[i++]);
	free(data_map->showmap);
	// ft_lstclear(data_map->player);
	// free(data_map->player);
	// //free_window(data_map);
	// ft_lstclear(data_map->enemy);
	// free(data_map->enemy);
	free(data_map);
	printf("Liberamos todo\n");
}

char	*get_dir(char	*dir)
{
	char	*aux;

	aux = ft_strjoin(dir, ".cub");
	dir = ft_strjoin("./srcs/assets/", aux);
	free(aux);
	return (dir);
}

int	main(int argc, char **argv)
{
	t_data_map	*map;
	int			check;
	char		*dir;

	atexit(leaks);
	if (argc != 2)
	{
		printf("Error no data inserted\n");
		return (0);
	}
	dir = get_dir(argv[1]);
	printf("%s\n",dir);
	map = mapreader(dir);
	check = mapcheck(map);
	if (check == 1)
	{
		printf("Check ok\n");
		make_window(map);
	}
	else
		printf("Check Error\n");
	free_all(map);
	free(dir);
	return (0);
}
