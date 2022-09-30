/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:38:08 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/09/29 16:31:54 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "map/data.h"
#include "engine/cub3d.h"

void	leaks(void)
{
	system("leaks -q test");
}

char	*get_dir(char	*dir)
{
	dir = ft_strjoin("./srcs/assets/", dir);
	return (dir);
}

int	main(int argc, char **argv)
{
	t_data_map	*data;
	char		*dir;

	atexit(leaks);
	if (argc != 2)
	{
		printf("Error no data inserted\n");
		return (0);
	}
	dir = get_dir(argv[1]);
	printf("%s\n", dir);
	data = mapreader(dir);
	// see_matrix(data->showmap);
	show_data(data);
	if (data_check(data))
	{
		printf("Iniciamos cube\n");
		cube(data);
	}
	free_all(data);
	free(dir);
	return (0);
}
