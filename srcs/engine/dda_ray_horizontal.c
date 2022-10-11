/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_ray_horizontal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:08:40 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/10/11 13:20:05 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	up(t_game *game, double angle, int r, float aTan)
{
	game->ray[r].ry = (((int)(game->player.f * M_SIZE) / M_SIZE)
			* M_SIZE) - 0.0001;
	if (is_angle(5 * (M_PI * 2) / 8, angle))
		game->ray[r].rx = ((int)(game->player.f * M_SIZE) - game->ray[r].ry)
			* aTan + game->player.c * M_SIZE + 0.0001;
	else
		game->ray[r].rx = ((int)(game->player.f * M_SIZE) - game->ray[r].ry)
			* aTan + game->player.c * M_SIZE;
	game->ray[r].yo = -M_SIZE;
	game->ray[r].xo = -game->ray[r].yo * aTan;
}

static void	down(t_game *game, double angle, int r, float aTan)
{
	(void)(angle);
	game->ray[r].ry = (((int)(game->player.f * M_SIZE) / M_SIZE)
			* M_SIZE) + M_SIZE;
	if (is_angle ((M_PI * 2) / 8, angle))
	{
		game->ray[r].rx = ((int)(game->player.f * M_SIZE) - game->ray[r].ry)
			* aTan + game->player.c * M_SIZE + 0.0001;
	}
	else
		game->ray[r].rx = ((int)(game->player.f * M_SIZE) - game->ray[r].ry)
			* aTan + game->player.c * M_SIZE;
	game->ray[r].yo = M_SIZE;
	game->ray[r].xo = -game->ray[r].yo * aTan;
}

static void	first_part(t_game *game, double angle, int r, float aTan)
{
	if (angle == 0 || angle == M_PI || angle == 2 * M_PI)
	{
		game->ray[r].hx = game->player.c * M_SIZE;
		game->ray[r].hy = game->player.f * M_SIZE;
		game->ray[r].dof = (game->size_c * M_SIZE) * (game->size_f * M_SIZE);
	}
	else if (angle > M_PI)
		up(game, angle, r, aTan);
	else if (angle < M_PI)
		down(game, angle, r, aTan);
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
			game->ray[r].hx = game->ray[r].rx;
			game->ray[r].hy = game->ray[r].ry;
			game->ray[r].disth = distance(game->player.c * M_SIZE,
					game->player.f * M_SIZE, game->ray[r].hx, game->ray[r].hy);
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

float	ray_vision_horizontal(t_game *game, double angle, int r, float aTan)
{
	game->ray[r].dof = 0;
	game->ray[r].disth = (game->size_c * M_SIZE) * (game->size_f * M_SIZE);
	game->ray[r].hx = game->player.c;
	game->ray[r].hy = game->player.f;
	first_part(game, angle, r, aTan);
	while (game->ray[r].dof < (game->size_c * game->size_f))
		last_part(game, r);
	return (game->ray[r].disth);
}
