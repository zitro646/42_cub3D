/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_ray_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:42:03 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/10/11 13:19:49 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	left(t_game *game, double angle, int r, float nTan)
{
	game->ray[r].rx = (((int)(game->player.c * M_SIZE) / M_SIZE)
			* M_SIZE) - 0.0001;
	if (is_angle (5 * (M_PI * 2) / 8, angle))
		game->ray[r].ry = ((int)(game->player.c * M_SIZE) - game->ray[r].rx)
			* nTan + game->player.f * M_SIZE + 0.0001;
	else
		game->ray[r].ry = ((int)(game->player.c * M_SIZE) - game->ray[r].rx)
			* nTan + game->player.f * M_SIZE;
	game->ray[r].xo = -M_SIZE;
	game->ray[r].yo = -game->ray[r].xo * nTan;
}

static void	right(t_game *game, double angle, int r, float nTan)
{
	game->ray[r].rx = (((int)(game->player.c * M_SIZE) / M_SIZE)
			* M_SIZE) + M_SIZE;
	if (is_angle ((M_PI * 2) / 8, angle))
		game->ray[r].ry = ((int)(game->player.c * M_SIZE) - game->ray[r].rx)
			* nTan + game->player.f * M_SIZE - 0.0001;
	else
		game->ray[r].ry = ((int)(game->player.c * M_SIZE) - game->ray[r].rx)
			* nTan + game->player.f * M_SIZE;
	game->ray[r].xo = M_SIZE;
	game->ray[r].yo = -game->ray[r].xo * nTan;
}

static void	first_part(t_game *game, double angle, int r, float nTan)
{
	if (angle == M_PI / 2 || angle == 3 * M_PI / 2)
	{
		game->ray[r].vx = game->player.c * M_SIZE;
		game->ray[r].vy = game->player.f * M_SIZE;
		game->ray[r].dof = game->size_c * game->size_f;
	}
	else if (angle > M_PI / 2 && angle < (3 * M_PI) / 2)
		left(game, angle, r, nTan);
	else if (angle < M_PI / 2 || angle > 3 * M_PI / 2)
		right(game, angle, r, nTan);
}

static void	last_part(t_game *game, int r)
{
	game->ray[r].my = (game->ray[r].ry) / M_SIZE;
	game->ray[r].mx = (game->ray[r].rx) / M_SIZE;
	if (inside_matrix(game, game->ray[r].my, game->ray[r].mx))
	{
		if (new_pos_is_wall(game->ray[r].my, game->ray[r].mx, game))
		{
			game->ray[r].dof = game->size_c * game->size_f;
			game->ray[r].vx = game->ray[r].rx;
			game->ray[r].vy = game->ray[r].ry;
			game->ray[r].distv = distance(game->player.c * M_SIZE,
					game->player.f * M_SIZE, game->ray[r].vx, game->ray[r].vy);
		}
		else
		{
			game->ray[r].rx += game->ray[r].xo;
			game->ray[r].ry += game->ray[r].yo;
			game->ray[r].dof++;
		}
	}
	else
		game->ray[r].dof = (game->size_c * M_SIZE) * (game->size_f * M_SIZE);
}

float	ray_vision_vertical(t_game *game, double angle, int r, float nTan)
{
	game->ray[r].dof = 0;
	game->ray[r].distv = (game->size_c * M_SIZE) * (game->size_f * M_SIZE);
	game->ray[r].vx = game->player.c;
	game->ray[r].vy = game->player.f;
	first_part(game, angle, r, nTan);
	while (game->ray[r].dof < (game->size_c * game->size_f))
		last_part(game, r);
	return (game->ray[r].distv);
}
