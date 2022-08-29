/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:05:07 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/08/29 20:48:41 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	// printf("%s\n",matrix[i]);
	while (matrix[i])
	{
		// printf("Liberamos -> %s\n",matrix[i]);
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_all(t_data_map *data_map)
{
	int	i;

	i = 0;
	// printf("Liberamos showmap\n");
	free_matrix(data_map->showmap);
	// printf("Liberamos -> %s\n",data_map->_north_texture_path);
	// printf("Liberamos -> %s\n",data_map->_south_texture_path);
	// printf("Liberamos -> %s\n",data_map->_east_texture_path);
	// printf("Liberamos -> %s\n",data_map->_west_texture_path);
	// printf("Liberamos -> %s\n",data_map->_roof_colour_path);
	// printf("Liberamos -> %s\n",data_map->_floor_colour_path);
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
	printf("Liberamos todo\n");
}


