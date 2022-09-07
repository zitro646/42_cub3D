/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:39:19 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/07 12:23:14 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		game->ray[i].ray = i;
	//	printf("ray[%i]:created\n", game->ray->ray);
		i++;
	}
}

void	ray(t_game *game)
{/*
	int	tile;
	double	next_xh;
	double	next_yh;

	tile = 50;*/
	printf("player(%f,%f)\n", game->player.y, game->player.x);
/*	game->ray[game->width/2].ray_angle = game->player.angle;
	printf("ray[%d] : %f\n", game->ray[game->width/2].ray,
			game->ray[game->width/2].ray_angle);

	game->ray[game->width/2].hit_y = (((int)game->player.y) / tile) * tile;
	if (game->player.looking_at == 2 || game->player.looking_at == 3)
		game->ray[game->width/2].hit_y += tile;

	game->ray[game->width/2].hit_x = ((game->ray[game->width/2].hit_y - game->player.y) /
		tan(game->ray[game->width/2].ray_angle)) + game->player.x;

	game->ray.step_y = tile;
	game->ray.step_x = (game->ray.step_y / tan(game->ray.ray_angle));
	if (game->player.looking_at == 1 || game->player.looking_at == 4) //if goes up
		game->ray.step_y =  -1 * tile;

	if (((game->player.looking_at == 3 || game->player.looking_at == 4)
				&& game->ray.step_x > 0)
			|| ((game->player.looking_at == 1 || game->player.looking_at == 2)
				&& game->ray.step_x < 0))
		game->ray.step_x = -1 * game->ray.step_x;

	next_xh = game->ray[game->width/2].hit_x;
	next_yh = game->ray[game->width/2].hit_y;

	if (game->player.looking_at == 1 || game->player.looking_at == 4)
		next_yh--;

//	*BUCLE COLISIóN*/

//	while(
		
} 
