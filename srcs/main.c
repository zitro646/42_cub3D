/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 10:38:08 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/09/01 16:28:22 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window/window.h"
#include <stdio.h>
#include "window/window.h"
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
	show_data(data);
	if (data_check(data))
	{
		printf("Check ok\n");
		//cube(data);
	}
	else
	{
		printf("Check Error\n");
	}
	free_all(data);
	free(dir);
	return (0);
}
