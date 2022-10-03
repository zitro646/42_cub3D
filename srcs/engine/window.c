/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:16:17 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/03 13:10:18 by potero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_vision(t_game *game, int color)
{
	double	line;
	int		i;
	int		j;

	line = 5;
	j = (game->player.c - 0.5) * 30 + 15;
	i = (game->player.f - 0.5) * 30 + 15;
	while (line < 10)
	{
		put_pixel(&game->mnmap,
			j + (cos(game->player.angle) * line),
			i + (sin(game->player.angle) * line), color);
		line += 0.2;
	}
}

void	player_pixel(t_game *game, int color, double f, double c)
{
	int	i;
	int	j;

	i = 10;
	while (i < 20)
	{
		j = 10;
		while (j < 20)
		{
			put_pixel(&game->mnmap,
				 ((c - 0.5) * 30) + j,
				 ((f - 0.5) * 30) + i, color);
			j++;
		}
		i++;
	}
		ray_vision(game, color);
}


void	wall_floor_pixel(t_game *game, int pos_f, int pos_c, int color)
 {
	int	i;
	int	j;
 
	i = 0;
	while (i < 30)
	{
		j = 0;
		while (j < 30)
		{
			if (i == 0 || j == 0)
				put_pixel(&game->mnmap,
					((pos_c * 30) + i), ((pos_f * 30 ) + j), 0x000000);
			else
				put_pixel(&game->mnmap,
					((pos_c * 30) + i), ((pos_f * 30 ) + j), color);
			j++;
		}
		i++;
	}
}

void	window(t_game *game, int start)
{
	int pos_f;
	int pos_c;

	pos_f = 0;
	while (pos_f < game->size_f)
	{
		pos_c = 0;
		while (pos_c < game->size_c)
		{
			if (game->matrix[pos_f][pos_c].value == '1')
				wall_floor_pixel(game, pos_f, pos_c, game->roof_color);
			else if (game->matrix[pos_f][pos_c].value != '1')
				wall_floor_pixel(game, pos_f, pos_c, game->floor_color);
			pos_c++;
		}
		pos_f++;
	}
	if (start == 1)
		player_pixel(game, 0x0000FF, game->player.f, game->player.c);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mnmap.image, 0, 0);
}
