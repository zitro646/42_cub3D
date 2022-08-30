/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:05:07 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/08/30 16:37:28 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	free_matrix(char **matrix, int opt_size)
{
	int	i;

	i = 0;
	if (opt_size == 0)
	{
		while (matrix[i])
			free(matrix[i++]);
	}
	else
	{
		while (i < opt_size)
			free(matrix[i++]);
	}
	free(matrix);
}

// void	free_str(char *str)
// {
// 	if (str)
// 		free(str);
// }

void	free_all(t_data_map *data_map)
{
	free_matrix(data_map->showmap, 0);
	free(data_map->_north_texture_path);
	free(data_map->_south_texture_path);
	free(data_map->_east_texture_path);
	free(data_map->_west_texture_path);
	free(data_map->_roof_colour_path);
	free(data_map->_floor_colour_path);
	// ft_lstclear(data_map->player);
	// free(data_map->player);
	// //free_window(data_map);
	// ft_lstclear(data_map->enemy);
	// free(data_map->enemy);
	free(data_map);
	printf("-> FREE ALL CALLED <-\n");
}


