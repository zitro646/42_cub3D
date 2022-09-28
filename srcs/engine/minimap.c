/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:56:01 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/28 13:24:03 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	minimap(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 0;
	i = game->player.f - 5;
	j = game->player.c - 5;
	while (x < 11)
	{
		y = 0;
		while (y < 11)
		{
			if ((i + x) < 0 || (i + x) >= game->size_f || (j + y) < 0
					|| (j + y) >= game->size_c)
				wall_floor_minimap(game, 635 + 15 * x, 635 + 15 * y, 0x000000);
			else if (game->matrix[i + x][j + y].value == '1')
				wall_floor_minimap(game, 635 + 15 * x, 635 + 15 * y, 0x27AE60);
			else if (game->matrix[i + x][j + y].value != '1')
				wall_floor_minimap(game, 635 + 15 * x, 635 + 15 * y, 0xDC7633);
			y++;
		}
		x++;
	}
	player_minimap(game, 0X0000FF);
}

void	ray_vision_minimap(t_game *game, int color)
{
	double	line;

	line = 5;
	while (line < 10)
	{
		mlx_pixel_put(game->mlx.mlx, game->mlx.screen,
				717 + (cos(game->player.angle) * line),
				717 + (sin(game->player.angle) * line), color);
		line += 0.2;
	}
}

void	player_minimap(t_game *game, int color)
{
	int		i;
	int		j;

	i = 5;
	while (i < 11)
	{
		j = 5;
		while (j < 11)
		{
			mlx_pixel_put(game->mlx.mlx, game->mlx.screen, 710 + j, 710 + i, color);
			j++;
		}
		i++;
	}
	ray_vision_minimap(game, color);
}

void	wall_floor_minimap(t_game *game, int pos_f, int pos_c, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 15)
	{
		j = 0;
		while (j < 15)
		{
			if (i == 0 || j == 0)
				mlx_pixel_put(game->mlx.mlx, game->mlx.screen,
					(pos_c + j), (pos_f + i), 0x000000);
			else
				mlx_pixel_put(game->mlx.mlx, game->mlx.screen,
					(pos_c + j), (pos_f + i), color);
			j++;
		}
		i++;
	}
}
