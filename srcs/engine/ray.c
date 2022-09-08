/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:39:19 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/08 10:54:28 by potero-d         ###   ########.fr       */
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

void    ray(t_game *game)
{
	int r;
	int	i;
	double	new_hit_x;
	double	new_hit_y;
	double	cont;

	r = game->width / 2;
	i = 0;
	game->ray[game->width / 2].ray_angle = game->player.angle;
	while (r < game->width)
	{
		game->ray[r].ray_angle = game->ray[game->width / 2].ray_angle
			+ game->diff_angle * i;
		if (game->ray[r].ray_angle > 2 * M_PI || game->ray[r].ray_angle < 0)
			game->ray[r].ray_angle = new_angle(game->ray[r].ray_angle);  
		r++;
		i++;
	}
	r = (game->width / 2) - 1;
	i = 0;
	while (r >= 0)
	{
		game->ray[r].ray_angle = game->ray[game->width / 2].ray_angle
				- game->diff_angle * i;
		if (game->ray[r].ray_angle > 2 * M_PI || game->ray[r].ray_angle < 0)
			game->ray[r].ray_angle = new_angle(game->ray[r].ray_angle); 
		r--;
		i++;
	}

	r = 0;
	while (r < game->width)
	{
		cont = 0.3;
		new_hit_x = (game->player.y * 15) + (cos(game->ray[r].ray_angle) * cont); 
		new_hit_y = (game->player.x * 15) + (sin(game->ray[r].ray_angle) * cont);
		while (!pos_is_wall(new_hit_x, new_hit_y, game))
		{
			new_hit_x = (game->player.y * 15) + (cos(game->ray[r].ray_angle) * cont); 
			new_hit_y = (game->player.x * 15) + (sin(game->ray[r].ray_angle) * cont);
			pos_is_wall(new_hit_x, new_hit_y, game);
			cont += 0.3;
		}
		game->ray[r].hit_y = new_hit_x / 15;
		game->ray[r].hit_x = new_hit_y / 15;
		r++;
	}
	printf("ray[0]: %f, hit[0]: (%f, %f)\n", game->ray[0].ray_angle,
			game->ray[0].hit_x, game->ray[0].hit_y);
	printf("ray[512]: %f, hit[512]: (%f, %f)\n", game->ray[512].ray_angle,
			game->ray[512].hit_x, game->ray[512].hit_y);
	printf("ray[1023]: %f, hit[1023]: (%f, %f)\n", game->ray[1023].ray_angle,
			game->ray[1023].hit_x, game->ray[0].hit_y);

}
