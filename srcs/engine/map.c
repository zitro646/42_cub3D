/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:52:30 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/07 12:57:33 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_pixel(t_game *game, int	color)
{
	int	i;
	int	j;
	double line;

	i = 5;
	while (i < 10)
	{
		j = 5;
		while (j < 10)
		{
			mlx_pixel_put(game->mlx.mlx, game->mlx.window,
				(game->player.y * 15) + j, (game->player.x * 15) + i, color);
			j++;
		}
		i++;
	}
	line = 0;
	while (line < 15)
	{
		j = cos(game->player.angle) * line;
		i = sin(game->player.angle) * line;
		mlx_pixel_put(game->mlx.mlx, game->mlx.window,
			(game->player.y * 15) + j + 7, (game->player.x * 15 ) + i + 7, color);
		line += 0.3;
	}
}	

void	wall_floor_pixel(t_game *game, int pos_x, int pos_y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 15)
	{
		j = 0;
		while (j < 15)
		{
			mlx_pixel_put(game->mlx.mlx, game->mlx.window,
				(pos_y * 15) + j, (pos_x * 15) + i, color);
			j++;
		}
		i++;
	}
}


void	image_aux(t_game *game, int pos_x, int pos_y)
{
	wall_floor_pixel(game, pos_x, pos_y, 0x8C8C8C);
	if (game->matrix[pos_x][pos_y].value == 'N')
	{
		game->player.x = pos_x;
		game->player.y = pos_y;
		player_pixel(game, 0X0000FF);
		game->player.angle = 3 * M_PI / 2;
		game->matrix[pos_x][pos_y].value = '0';
	}

	else if (game->matrix[pos_x][pos_y].value == 'S')
	{
		game->player.x = pos_x;
		game->player.y = pos_y;
		player_pixel(game, 0X0000FF);
		game->player.angle = (M_PI / 2);
		game->matrix[pos_x][pos_y].value = '0';
	}
	else if (game->matrix[pos_x][pos_y].value == 'O')
	{
		game->player.x = pos_x;
		game->player.y = pos_y;
		player_pixel(game, 0X0000FF);
		game->player.angle = M_PI;
		game->matrix[pos_x][pos_y].value = '0';
	}
	else if (game->matrix[pos_x][pos_y].value == 'E')
	{
		game->player.x = pos_x;
		game->player.y = pos_y;
		player_pixel(game, 0X0000FF);
		game->player.angle = 0;
		game->matrix[pos_x][pos_y].value = '0';
	}
}

void	image(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = 0;
	while (pos_x < game->size_x)
	{
		pos_y = 0;
		while (pos_y < game->size_y)
		{
			if (game->matrix[pos_x][pos_y].value == '1')
				wall_floor_pixel(game, pos_x, pos_y, 0x4B0082);
			else if (game->matrix[pos_x][pos_y].value != '1')
			{
				image_aux(game, pos_x, pos_y);
			}
			pos_y++;
		}
		pos_x++;
	}
}
