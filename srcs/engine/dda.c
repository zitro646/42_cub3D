/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:47:50 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/26 18:00:54 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


double	dda(t_game *game, int r)
{
	double	pos_xh;
	double	pos_yh;

	double	pos_xv;
	double	pos_yv;

	double	tangle;
	double	aux;
	int		valid;

	tangle = tan(game->ray[r].ray_angle);
	valid = 0;

	pos_xv = game->player.x - 0.5;
	if (game->ray[r].ray_angle > (3 * M_PI / 2) || game->ray[r].ray_angle < (M_PI / 2))
		pos_xv++;
	pos_yv = game->player.y + (0.5 * tangle);

	if (game->ray[r].ray_at == 3 || game->ray[r].ray_at == 4) 
	{
		aux = round(pos_yv) - pos_yv;
		pos_yv = round(pos_yv) + aux;
	}
	if (game->ray[r].ray_at == 3) 
		pos_yv++;
	if (game->ray[r].ray_at == 4) 
		pos_yv--;
	printf("%i(xv, yv): %f, %f\n", r, pos_xv, pos_yv);

	if (pos_xv < 0 || pos_xv >= game->size_y || pos_yv < 0 || pos_yv >= game->size_x)
		valid = 1;
/*
	while (!is_wall((int)pos_xv, (int)pos_yv, game) && valid != 1) 
	{
		pos_xv -= 1;
		pos_yv += tangle;
		if (pos_xv < 0 || pos_xv >= game->size_y || pos_yv < 0 || pos_yv >= game->size_x)
			valid = 1;
	}
*/
	printf("%i(xv, yv): %f, %f\n", r, pos_xv, pos_yv);

	pos_yh = game->player.y - 0.5;
	if (game->ray[r].ray_angle > 0 && game->ray[r].ray_angle < M_PI)
		pos_yh++;
	pos_xh = game->player.x - (0.5 / tangle);

	if (game->ray[r].ray_at == 2)
	{
		aux = round(pos_xh) - pos_xh;
		pos_xh = round(pos_xh) + aux;
		pos_xh++;
	}
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

