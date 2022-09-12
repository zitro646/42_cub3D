/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:07:53 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/12 13:52:03 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	screen_game(t_game *game)
{
//	int		r;
//	double	proportion;
	int		x;
	int		y;
	int		start;
	int		end;
	double	middle;
//	double	point;

//	proportion = 85.33;
	middle = game->height / 2;
	x = 0;
	while (x < game->width)
	{
		y = 0;
		start = middle - (game->ray[x].wall / 2);
		end = start + (int) game->ray[x].wall;
	//	if (x == 0 || x == 512 || x == 1023)
	//		printf("y_[%d]: %d: %d\n", x, start, end);
		if ( x%4 == 0)
		{
			while (y < start)
			{
			mlx_pixel_put(game->mlx.mlx, game->mlx.screen, x, y, 0x000000);
			y++;
			}
			while (y < end)
			{
				mlx_pixel_put(game->mlx.mlx, game->mlx.screen, x, y, 0x4B0082);
				y++;
			}
			while (y < game->height)
			{
				mlx_pixel_put(game->mlx.mlx, game->mlx.screen, x, y, 0xFF0000);
				y++;
			}
		}
		x++;
	}
}

