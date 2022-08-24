/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:04:39 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/08/24 13:45:06 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

t_window	*init_window(void)
{
	int			i;
	t_window	*window;

	i = 32;
	window = ft_calloc(sizeof(t_window), 1);
	window->mlx_ptr = mlx_init();
	// window->floor_title = mlx_xpm_file_to_image(window->mlx_ptr, \
	// 	"./srcs/assets/Floor.xpm", &i, &i);
	// window->player_title = mlx_xpm_file_to_image(window->mlx_ptr, \
	// 	"./srcs/assets/Character.xpm", &i, &i);
	// window->wall_title = mlx_xpm_file_to_image(window->mlx_ptr, \
	// 	"./srcs/assets/Wall.xpm", &i, &i);
	// window->coin_title = mlx_xpm_file_to_image(window->mlx_ptr, \
	// 	"./srcs/assets/Coin.xpm", &i, &i);
	// window->exit_title = mlx_xpm_file_to_image(window->mlx_ptr, \
	// 	"./srcs/assets/Door.xpm", &i, &i);
	// window->enemy_title = mlx_xpm_file_to_image(window->mlx_ptr, \
	// 	"./srcs/assets/Enemy.xpm", &i, &i);
	return (window);
}

// void	draw_image(t_data_map *data_map, int y, int x)
// {
// 	t_window	*window;

// 	window = data_map->window;
// 	if (data_map->showmap[y][x] == '1')
// 		mlx_put_image_to_window(window->mlx_ptr,
// 			window->win_ptr, window->wall_title, x * 32, y * 32);
// 	else if (data_map->showmap[y][x] == '0')
// 		mlx_put_image_to_window(window->mlx_ptr,
// 			window->win_ptr, window->floor_title, x * 32, y * 32);
// 	else if (data_map->showmap[y][x] == 'C')
// 		mlx_put_image_to_window(window->mlx_ptr,
// 			window->win_ptr, window->coin_title, x * 32, y * 32);
// 	else if (data_map->showmap[y][x] == 'P')
// 		mlx_put_image_to_window(window->mlx_ptr,
// 			window->win_ptr, window->player_title, x * 32, y * 32);
// 	else if (data_map->showmap[y][x] == 'E')
// 		mlx_put_image_to_window(window->mlx_ptr,
// 			window->win_ptr, window->exit_title, x * 32, y * 32);
// 	else if (data_map->showmap[y][x] == 'X')
// 		mlx_put_image_to_window(window->mlx_ptr,
// 			window->win_ptr, window->enemy_title, x * 32, y * 32);
// }

// void	set_window(t_data_map *data_map)
// {
// 	int			x;
// 	int			y;
// 	t_window	*window;

// 	window = data_map->window;
// 	y = 0;
// 	while (data_map->showmap[y] != '\0')
// 	{
// 		x = 0;
// 		while (data_map->showmap[y][x] != '\0')
// 		{
// 			draw_image(data_map, y, x);
// 			x++;
// 		}
// 		y++;
// 	}
// }
