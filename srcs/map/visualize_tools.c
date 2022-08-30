/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:25:22 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/08/30 16:46:10 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h" 

void	see_matrix(char **map)
{
	int	y;

	y = 0;
	printf ("Matrix %p\n", &map);
	while (map[y])
	{
		if (y < 10)
			printf (" %i - %p - '%s'\n", y, &map[y], map[y]);
		else
			printf ("%i - %p - '%s'\n", y, &map[y], map[y]);
		y++;
	}
}

void	show_data(t_data_map *data)
{
	if (!data)
	{
		printf("No data\n");
		return ;
	}
	see_matrix(data->showmap);
	printf("%p - NO : '%s'\n", &data->_north_texture_path, data->_north_texture_path);
	printf("%p - SO : '%s'\n", &data->_south_texture_path, data->_south_texture_path);
	printf("%p - EA : '%s'\n", &data->_east_texture_path, data->_east_texture_path);
	printf("%p - WE : '%s'\n", &data->_west_texture_path, data->_west_texture_path);
	printf("%p - C  : '%s'\n", &data->_roof_colour_path, data->_roof_colour_path);
	printf("%p - F  : '%s'\n", &data->_floor_colour_path, data->_floor_colour_path);
	
}
