/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:47:50 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/26 13:56:31 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	dda(t_game *game, int r)
{
	double	pos_xh;
	double	pos_yh;

	double	pos_xv;
	double	pos_yv;

	pos_xv = game->player.x - 0.5;
	if (game->ray[r].ray_at == 1 || game->ray[r].ray_at == 2)
		pos_xv++;
	pos_yv = game->player.y + (0.5 * tan(game->ray[r].ray_angle));
	if (game->ray[r].ray_at == 3) 
		pos_yv++;
	if (game->ray[r].ray_at == 4) 
		pos_yv--;

	printf("%i: %f\n", r, game->ray[r].ray_angle);
	printf("%iat: %i\n", r, game->ray[r].ray_at);
	printf("%i(xv, yv): %f, %f\n", r, pos_xv, pos_yv);


	pos_yh = game->player.y -0.5;
	if (game->ray[r].ray_at == 2 || game->ray[r].ray_at == 3)
		pos_yh++;
	pos_xh = game->player.x - (0.5 / tan(game->ray[r].ray_angle));
	if (game->ray[r].ray_at == 2) 
		pos_xh++;
	if (game->ray[r].ray_at == 3) 
		pos_xh--;

	printf("%i(xh, yh): %f, %f\n", r, pos_xh, pos_yh);
/*
	printf("M_PI / 2 = %f\n", (M_PI/2));
	printf("M_PI  = %f\n", (M_PI));
	printf("3M_PI / 2  = %f\n", (3 * M_PI/2));
	printf("2M_PI  = %f\n", (2 * M_PI));
*/
	return (0);
}

