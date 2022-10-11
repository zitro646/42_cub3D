/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:56:01 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/11 14:18:14 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	aux_minimap(t_game *game)
{
	int	x;
	int	y;

	y = -4;
	while (y < 5)
	{
		x = -4;
		while (x < 5)
		{
			if (!inside_matrix(game, (int) game->player.f + y,
					(int) game->player.c + x))
				wall_floor_minimap(game, y + 4, x + 4, 0x000000);
			else if (game->matrix[(int)game->player.f + y]
				[(int)game->player.c + x].value == '1')
				wall_floor_minimap(game, y + 4, x + 4, game->roof_color);
			else if (game->matrix[(int)game->player.f + y]
				[(int)game->player.c + x].value != '1')
				wall_floor_minimap(game, y + 4, x + 4, game->floor_color);
			x++;
		}
		y++;
	}
}

void	minimap(t_game *game)
{
	aux_minimap(game);
	player_minimap(game, 0X0000FF);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.screen,
		game->minimap.image, game->height - 140, game->width - 140);
}

void	ray_vision_minimap(t_game *game, int color)
{
	double	line;

	line = 5;
	while (line < 10)
	{
		put_pixel(&game->minimap,
			67 + (cos(game->player.angle) * line),
			67 + (sin(game->player.angle) * line), color);
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
			put_pixel(&game->minimap, (60 + i), (60 + j), color);
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
			if (i == 0 || j == 0 || i == 14 || j == 14)
				put_pixel(&game->minimap,
					(pos_c * 15 + i), (pos_f * 15 + j), 0x000000);
			else
				put_pixel(&game->minimap,
					(pos_c * 15 + i), (pos_f * 15 + j), color);
			j++;
		}
		i++;
	}
}
