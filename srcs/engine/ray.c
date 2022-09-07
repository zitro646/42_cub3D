/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:39:19 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/07 16:36:11 by potero-d         ###   ########.fr       */
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

	r = 0;
	while (r < game->width)
	{
		if (r == 0)
		{
			game->ray[r].ray_angle = game->player.angle - M_PI / 4;
			if (game->player.angle > (2 * M_PI) || game->player.angle < 0)
				game->ray[r].ray_angle = new_angle(game->ray[r].ray_angle);
		}
		else
			game->ray[r].ray_angle = game->ray[0].ray_angle + game->diff_angle * r;
		r++;
	}

	printf("ray[0]: %f\n", game->ray[0].ray_angle);
	printf("ray[512]: %f\n", game->ray[512].ray_angle);
	printf("ray[1023]: %f\n", game->ray[1023].ray_angle);
}
