/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:44:26 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/10/18 16:32:01 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
// file == y
// column == x

static void	aux_fill(t_newray *ray, t_game *game)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (game->player.c - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - game->player.c) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (game->player.f - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - game->player.f) * ray->deltadisty;
	}
}

static t_newray	fill_raycaster(t_game *game, int x)
{
	t_newray	ray;

	ray.camerax = 2 * x / (double)W_WINDOW_SIZE - 1;
	// ray.raydirx = game.player.dirx + game.player.planex * ray.camerax;
	// ray.raydiry = game.player.diry + game.player.planey * ray.camerax;
	ray.mapx = (int)game->player.c;
	ray.mapy = (int)game->player.f;
	if (ray.raydirx == 0)
		ray.deltadistx = 1e30;
	else
		ray.deltadistx = fabs(1 / ray.raydirx);
	if (ray.raydiry == 0)
		ray.deltadisty = 1e30;
	else
		ray.deltadisty = fabs(1 / ray.raydiry);
	ray.hit = 0;
	aux_fill(&ray, game);
	return (ray);
}
