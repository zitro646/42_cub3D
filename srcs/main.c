/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:38:08 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/10/11 13:41:41 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "map/data.h"
#include "engine/cub3d.h"

void	leaks(void)
{
	system("leaks -q test");
}

char	*get_dir(char *dir)
{
	dir = ft_strjoin("./srcs/assets/", dir);
	if (!ft_strnstr(&dir[ft_strlen(dir) - 4], ".cub", ft_strlen(dir)))
	{
		printf("No .cub detected\n");
		free(dir);
		return (NULL);
	}
	else
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
	show_data(data);
	if (data_check(data))
	{
		printf("Iniciamos cube\n");
		cube(data);
	}
	else
	{
		printf("Check Error\n");
	}
	free_all(data);
	free(dir);
	return (0);
}
