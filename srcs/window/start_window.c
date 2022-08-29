/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:40:31 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/08/29 16:28:36 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int	get_array_max_size(char **array)
{
	int	x_max;
	int	i;
	int	j;

	i = 0;
	j = 0;
	x_max = 0;
	while (array[j])
	{
		while (array[j][i] != 0)
			i++;
		if (x_max < i)
			x_max = i;
		i = 0;
		j++;
	}
	return (x_max);
}

void	make_window(t_data_map *data_map)
{
	int			x;
	int			y;
	t_window	*window;

	y = data_map->height;
	x = get_array_max_size(data_map->showmap);
	printf("Tamaño maximo del mapa es %i \n",x);
	data_map->window = init_window();
	window = data_map->window;
	window->win_ptr = mlx_new_window(window->mlx_ptr, x * 32, y * 32, \
		"Cub3D");
	// set_window(data_map);
	// mlx_hook(window->win_ptr, 17, 0, ft_red_cross, data_map);
	// //mlx_key_hook(window->win_ptr, key_hook, data_map);
	mlx_loop(window->mlx_ptr);
}
