/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:39:19 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/13 11:18:52 by potero-d         ###   ########.fr       */
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
		i++;
	}
}

void	ray_angle(t_game *game)
{
	int	r;
	int	i;

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
}

void	ray_hit(t_game *game)
{
	int		r;
	double	new_hit_x;
	double	new_hit_y;
	double	cont;

	r = 0;
	while (r < game->width)
	{
		cont = 0.25;
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
}

void	ray_distance(t_game *game)
{
	int		r;
	double	pow_x;
	double	pow_y;
	double	abs;

	r = 0;
	while (r < game->width)
	{
		pow_x = pow(game->ray[r].hit_x - game->player.x, 2);
		pow_y = pow(game->ray[r].hit_y - game->player.y, 2);
		abs = pow_x + pow_y;
		if (abs < 0)
			abs *= - 1;
		game->ray[r].distance = sqrt(abs);
		r++;
	}
}



void    ray(t_game *game)
{
	int 	r;
	double	angle;
	double	aux;
	double	proportion;

	ray_angle(game);
	ray_hit(game);
	ray_distance(game);
	r = 0;
	while (r < game->width)
	{
		angle = - M_PI / 4 + (game->diff_angle * r);
		game->ray[r].point = cos(angle) * game->ray[r].distance;
		r++;
	}
	ray_at(game);
	aux = 500;
	proportion = tan(M_PI / 4) * (game->width / 2);
	r = 0;
	while (r < game->width)
	{
		game->ray[r].wall = aux /(aux / proportion * game->ray[r].point);
		r++;
	}
/*
	printf("ray[0]: %f, hit[0]: (%f, %f)\n", game->ray[0].ray_angle,
			game->ray[0].hit_x, game->ray[0].hit_y);
	printf("looking at: %d\n", game->ray[0].ray_at);
	printf("distance to hit: %f\n", game->ray[0].distance);
	printf("point: %f\n", game->ray[0].point);
	printf("wall size: %f\n", game->ray[0].wall);

	printf("ray[512]: %f, hit[512]: (%f, %f)\n", game->ray[512].ray_angle,
			game->ray[512].hit_x, game->ray[512].hit_y);
	printf("looking at: %d\n", game->ray[512].ray_at);
	printf("distance to hit: %f\n", game->ray[512].distance);
	printf("point: %f\n", game->ray[512].point);
	printf("wall size: %f\n", game->ray[512].wall);

	printf("ray[1023]: %f, hit[1023]: (%f, %f)\n", game->ray[1023].ray_angle,
			game->ray[1023].hit_x, game->ray[1023].hit_y);
	printf("looking at: %d\n", game->ray[1023].ray_at);
	printf("distance to hit: %f\n", game->ray[1023].distance);
	printf("point: %f\n", game->ray[1023].point);
	printf("wall size: %f\n", game->ray[1023].wall);
*/
}
