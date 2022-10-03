/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:11:36 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/10/03 10:32:31 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int test_version_tests(char *str_dir)
{
	(void)str_dir;
	void *mlx_pointer;
	int width;
	int height;

	width = 15;
	height = 15;
	mlx_pointer = ft_calloc(sizeof(void *), 1);
	// void	*mlx_xpm_file_to_image(mlx_pointer, str_dir, width, height);
	printf("Path : %s\n",str_dir);

	return (0);
}