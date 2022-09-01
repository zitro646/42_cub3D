/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:40:31 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/09/01 13:56:37 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	make_window(t_data_map *data_map)
{
	int			x;
	int			y;
	t_window	*window;

	y = data_map->height;
	//x = get_array_max_size(data_map->showmap);
	x = 0;
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
