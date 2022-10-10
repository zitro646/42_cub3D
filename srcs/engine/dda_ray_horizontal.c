/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_ray_horizontal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:08:40 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/10/10 13:29:14 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

 ray_vision_horizontal(t_game *game, double angle, int r, float aTan)
{
	int		dof 
	float	hx;
	float	hy;
	float 	distH;
	float	rx;
	float	ry;

	dof = 0;
	distH = (game->size_c * M_SIZE) * (game->size_f * M_SIZE);
	hx = game->player.c;
	hy = game->player.f;
	if (angle == 0 || angle == M_PI || angle == 2 * M_PI)
	{
		hx = game->player.c * M_SIZE;
		hy = game->player.f * M_SIZE;
		dof = (game->size_c * M_SIZE) * (game->size_f * M_SIZE);
	}
	else if (angle > M_PI)
	{
		ry = (((int)(game->player.f * M_SIZE) / M_SIZE ) * M_SIZE ) - 0.0001;
		if (is_angle(5 * (M_PI * 2) / 8,angle))
			rx = ((int)(game->player.f * M_SIZE) - ry)
				* aTan + game->player.c * M_SIZE + 0.0001;
		else
			rx = ((int)(game->player.f * M_SIZE) - ry)
				* aTan + game->player.c * M_SIZE;
		yo = -M_SIZE;
		xo = -yo * aTan;
	}
	else if (angle < M_PI)
	{
		ry = (((int)(game->player.f * M_SIZE) / M_SIZE ) * M_SIZE ) + M_SIZE;
		if (is_angle ((M_PI * 2) / 8, angle))
		{
			rx = ((int)(game->player.f * M_SIZE) - ry)
				* aTan + game->player.c * M_SIZE + 0.0001;
		}
		else
			rx = ((int)(game->player.f * M_SIZE) - ry)
				* aTan + game->player.c * M_SIZE;
		
		yo = M_SIZE;
		xo = -yo * aTan;
	}
	while (dof < (game->size_c * game->size_f))
	{
		my = (ry) / M_SIZE;
		mx = (rx) / M_SIZE;
		if (inside_matrix(game,my,mx))
		{
			if (new_pos_is_wall(my,mx,game))
			{
				dof = game->size_c * game->size_f;
				hx = rx;
				hy = ry;
				distH = distance(game->player.c * M_SIZE,game->player.f * M_SIZE,hx,hy);
			}
			else
			{
				rx += xo;
			 	ry += yo;
			 	dof++;
			}
		}
		else
		{
			dof = (game->size_c * M_SIZE) * (game->size_f * M_SIZE);
		}

	}
