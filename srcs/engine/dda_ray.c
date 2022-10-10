/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:45:51 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/10/10 17:05:09 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	inside_matrix(t_game *game, int f, int c)
{
	if (f < game->size_f && f >= 0 && c < game->size_c && c >= 0)
	{
		return (1);
	}
	return (0);
}

float	distance(float ax, float ay, float bx, float by)
{
	return (sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay))));
}

int	new_pos_is_wall( int y, int x, t_game *game)
{
	if (game->matrix[y][x].value == '1')
	{
		return (1);
	}
	return (0);
}

int	hit_check(int my, int mx, float angle, t_game *game)
{
	int	new_angle;
	int	testing;

	new_angle = angle * 1000000;
	testing = 5 * (M_PI * 2) / 8 * 1000000;
	if (new_pos_is_wall(my, mx, game))
	{
		return (1);
	}
	if (new_angle == testing)
	{	
		if (new_pos_is_wall(my + 1, mx, game))
			return (2);
		if (new_pos_is_wall(my, mx + 1, game))
			return (2);
	}
	testing = (M_PI * 2) / 8 * 1000000;
	if (new_angle == testing)
	{	
		if (new_pos_is_wall(my - 1, mx, game))
			return (3);
		if (new_pos_is_wall(my, mx - 1, game))
			return (3);
	}
	return (0);
}

double	ray_vision_dda(t_game *game, double angle, int r)
{
	float	rx;
	float	ry;
	float	disth;
	float	distv;

	disth = ray_vision_horizontal(game, angle, r, (-1 / tan(angle)));
	distv = ray_vision_vertical(game, angle, r, -tan(angle));
	if (distv < disth)
	{
		rx = game->ray[r].vx;
		ry = game->ray[r].vy;
		game->ray[r].wall_hit = VERTICAL;
	}
	else
	{
		rx = game->ray[r].hx;
		ry = game->ray[r].hy;
		game->ray[r].wall_hit = HORIZONTAL;
	}
	game->ray[r].hit_f = rx / M_SIZE;
	game->ray[r].hit_c = ry / M_SIZE;
	return (distance(game->player.c * M_SIZE, game->player.f
			* M_SIZE, rx, ry) / M_SIZE);
}
