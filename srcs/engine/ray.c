/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:39:19 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/07 14:06:04 by potero-d         ###   ########.fr       */
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
{
	int	tile;
	int	r;
	double	next_xh;
	double	next_yh;
	int		tile_x;
	int		tile_y;
	int		hit;

	r = game->width/2;
	tile = 15;
	printf("player(%f,%f)\n", game->player.y, game->player.x);
	game->ray[r].ray_angle = game->player.angle;
	printf("ray[%d] : %f\n", game->ray[r].ray, game->ray[r].ray_angle);

	game->ray[r].hit_y = (((int)game->player.y) / tile) * tile;
	if (game->player.looking_at == 2 || game->player.looking_at == 3)
		game->ray[r].hit_y += tile;

	game->ray[game->width/2].hit_x = ((game->ray[r].hit_y - game->player.y) /
		tan(game->ray[r].ray_angle)) + game->player.x;

	game->ray[r].step_y = tile;
	game->ray[r].step_x = (game->ray[r].step_y / tan(game->ray[r].ray_angle));
	if (game->player.looking_at == 1 || game->player.looking_at == 4)
		game->ray[r].step_y =  -1 * tile;

	if (((game->player.looking_at == 3 || game->player.looking_at == 4)
				&& game->ray[r].step_x > 0)
			|| ((game->player.looking_at == 1 || game->player.looking_at == 2)
				&& game->ray[r].step_x < 0))
		game->ray[r].step_x = -1 * game->ray[r].step_x;

	next_xh = game->ray[r].hit_x;
	next_yh = game->ray[r].hit_y;

	if (game->player.looking_at == 1 || game->player.looking_at == 4)
		next_yh--;

	/*BUCLE COLISIóN*/

	hit = 0;
	printf("HERE\n");
	while (hit == 0)
	{
		tile_x = next_xh / tile;
		tile_y = next_yh / tile;
		printf("tile_x : %d\n", tile_x);
		printf("tile_y : %d\n", tile_y);
		if (game->matrix[tile_x][tile_y].value == '1')
		{
			game->ray[r].wall_hitx_h = next_xh;
			game->ray[r].wall_hity_h = next_yh;
			hit = 1;
		}
		else
		{
			next_xh += game->ray[r].step_x;
			next_yh += game->ray[r].step_y;
		}
	}
	printf("ColisionX: (%f, %f)\n", game->ray[r].wall_hitx_h, game->ray[r].wall_hity_h);

} 
