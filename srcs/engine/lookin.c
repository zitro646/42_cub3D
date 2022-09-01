/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:14:52 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/01 12:39:54 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    looking_at(t_game *game)
{
	if (game->direction == 1)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_n,
			(game->player.y * 15), (game->player.x * 15));
	else if (game->direction == 3)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_s,
			(game->player.y * 15), (game->player.x * 15));
	else if (game->direction== 4)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_o,
			(game->player.y * 15), (game->player.x * 15));
	else if (game->direction== 2)
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_e,
			(game->player.y * 15), (game->player.x * 15));
	player_pixel(game);
}

void	dir_x_y(t_game *game)
{
	if (game->direction == 1)
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0;
	}
	else if (game->direction == 3)
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
	}
	else if (game->direction== 4)
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
	}
	else if (game->direction== 2)
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0;
	}
}

void	look_left(t_game *game)
{
	if (game->direction == 1)
		game->direction = 4;
	else if (game->direction == 3)
		game->direction = 2;
	else if (game->direction == 4)
		game->direction = 3;
	else if (game->direction== 2)
		game->direction = 1;
	looking_at(game);
	dir_x_y(game);
}

void	look_right(t_game *game)
{
	if (game->direction == 1)
		game->direction = 2;
	else if (game->direction == 3)
		game->direction = 4;
	else if (game->direction== 4)
		game->direction = 1;
	else if (game->direction== 2)
		game->direction = 3;
	looking_at(game);
	dir_x_y(game);
}

int	dir(char value)
{
	if (value == 'N')
		return (1);
	else if (value == 'E')
		return (2);
	else if (value == 'S')
		return (3);
	else if (value == 'O')
		return (4);
	return (0);
}
