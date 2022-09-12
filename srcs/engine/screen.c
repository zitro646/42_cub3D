/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:07:53 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/12 15:55:20 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	screen_game(t_game *game)
{
	int		x;
	int		y;
	int		start;
	int		end;
	double	middle;

	middle = game->height / 2;
	x = 0;
	while (x < game->width)
	{
		y = 0;
		start = middle - (game->ray[x].wall / 2);
		end = start + (int) game->ray[x].wall;
		if ( x % 2 == 0)
		{
			while (y < start)
			{
			mlx_pixel_put(game->mlx.mlx, game->mlx.screen, x, y, 0xFF0000);
			y++;
			}
			while (y < end)
			{
				mlx_pixel_put(game->mlx.mlx, game->mlx.screen, x, y, 0xFFFF00);
				y++;
			}
			while (y < game->height)
			{
				mlx_pixel_put(game->mlx.mlx, game->mlx.screen, x, y, 0x4B0082);
				y++;
			}
		}
		x++;
	}
}

