/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:07:53 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/08 12:07:48 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	screen_game(t_game *game)
{
	int		r;
	double	proportion;
	double	x;
	double	y;
	int		point;

	proportion = 85.33;
	r = 0;
	while (r < game->width)
	{
		x = r;
		point = game->ray[r].distance * proportion;
		y = 0;
		while (y < game->height)
		{
			if ( y <= point)
				mlx_pixel_put(game->mlx.mlx, game->mlx.screen, x, y, 0x4B0082);
			y++;
		}
		r++;
	}
}

