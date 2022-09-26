/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:39:19 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/26 16:59:12 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_wall( int x, int y, t_game *game)
{
//	int x;
//	int y;

//	x = x_pixel;
//	y = y_pixel;
//	printf("(x,y): %d,%d\n", x, y);
	if (game->matrix[y][x].value == '1')
		return (1);
	return (0);
}

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

void	ray_hit(t_game *game, int r)
{
	double	new_hit_x;
	double	new_hit_y;
	double	cont;
	double	cos_const;
	double	sin_const;

	cont = 0;
	cos_const = cos(game->ray[r].ray_angle);
	sin_const = sin(game->ray[r].ray_angle);
//	new_hit_y = (game->player.x * 15) + (sin_const * cont);
//	new_hit_x = (game->player.y * 15) + (cos_const * cont);
	new_hit_x = (game->player.y) + (cos_const * cont);
	new_hit_y = (game->player.x) + (sin_const * cont);
//	if (r == 250)
//		printf("hit: (%f, %f)\n", new_hit_x, new_hit_y);
//	new_hit_y = (game->player.x * 15) + (sin(game->ray[r].ray_angle) * cont);
//	new_hit_x = (game->player.y * 15) + (cos(game->ray[r].ray_angle) * cont); 
//	while (!pos_is_wall(new_hit_x, new_hit_y, game))
	while (!is_wall((int)new_hit_x,(int) new_hit_y, game))
	{
	//	new_hit_y = (game->player.x * 15) + (sin_const * cont);
	//	new_hit_x = (game->player.y * 15) + (cos_const * cont);
		new_hit_x = (game->player.y) + (cos_const * cont);
		new_hit_y = (game->player.x) + (sin_const * cont);

	//	if (r == 250)
	//		printf("hit: (%f, %f)\n", new_hit_x, new_hit_y);
	//	new_hit_x = (game->player.y * 15) + (cos(game->ray[r].ray_angle) * cont); 
	//	new_hit_y = (game->player.x * 15) + (sin(game->ray[r].ray_angle) * cont);
		cont += 0.01;
	}

//	game->ray[r].hit_y = new_hit_x / 15;
//	game->ray[r].hit_x = new_hit_y / 15;
	game->ray[r].hit_y = new_hit_x;
	game->ray[r].hit_x = new_hit_y;
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
		ray_at(game, r);
		
		ray_hit(game, r);

		game->ray[r].distance = sqrt(pow(game->ray[r].hit_x - game->player.x, 2)
			+ pow(game->ray[r].hit_y - game->player.y, 2));

	//	game->ray[r].distance = vision_dda(game, game->ray[r].ray_angle);

		if (r == 260 || r == 250 || r == 240 || r == 0 || r == 499)
			dda(game, r);

		angle = - M_PI / 4 + (game->diff_angle * r);
		game->ray[r].point = cos(angle) * game->ray[r].distance;
		game->ray[r].wall = wall /(wall / proportion * game->ray[r].point);
		r++;
	}
/*
	printf("ray[0]: %f, hit[0]: (%f, %f)\n", game->ray[0].ray_angle,
			game->ray[0].hit_x, game->ray[0].hit_y);
	printf("looking at: %d\n", game->ray[0].ray_at);
	printf("distance to hit: %f\n", game->ray[0].distance);
	printf("point: %f\n", game->ray[0].point);
	printf("wall size: %f\n", game->ray[0].wall);
*/
}
