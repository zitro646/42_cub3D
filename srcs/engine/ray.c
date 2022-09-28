/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:39:19 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/28 14:31:14 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_angle(t_game *game, int r)
{
	int	i;

	i = game->width / 2;
	if (r == game->width / 2)
		game->ray[r].ray_angle = game->player.angle;
	else if (r < i)
	{
		game->ray[r].ray_angle = game->player.angle
			- game->diff_angle * (i - r);
	}
	else if (r > i)
	{
		game->ray[r].ray_angle = game->player.angle
				+ game->diff_angle * (r - i);
		if (game->ray[r].ray_angle > 2 * M_PI || game->ray[r].ray_angle < 0)
			game->ray[r].ray_angle = new_angle(game->ray[r].ray_angle); 
	}
	if (game->ray[r].ray_angle > 2 * M_PI || game->ray[r].ray_angle < 0)
			game->ray[r].ray_angle = new_angle(game->ray[r].ray_angle);
}

void    ray(t_game *game)
{
	int 	r;
	double	angle;
	double	wall;
	double	proportion;

	wall = game->width / 2;
	proportion = tan(M_PI / 4) * (game->width / 2);
	r = 0;
	while (r < game->width)
	{
		ray_angle(game, r);
//		ray_at(game, r);
		
//		game->ray[r].distance = sqrt(pow(game->ray[r].hit_f - game->player.f, 2)
//			+ pow(game->ray[r].hit_c - game->player.c, 2));
		game->ray[r].distance = ray_vision_dda(game, game->ray[r].ray_angle);
		angle = - M_PI / 4 + (game->diff_angle * r);
		game->ray[r].point = cos(angle) * game->ray[r].distance;
		game->ray[r].wall = wall /(wall / proportion * game->ray[r].point);
		screen_game_r(game, r);
		r++;
	}
}
