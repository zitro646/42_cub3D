/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:33:35 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/26 15:45:21 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

 //Normalizar el angulo (que esté en el primer giro siempre)
void    angle(t_game *game)
{
	double  new;
	double  num;

	num = game->player.angle;
	while (num >= 0)
		num -= (2 * M_PI);
	num += (2 * M_PI);
	if (game->player.angle < 0)
		new = num + (2 * M_PI);
	else
		new = num;
	if (new == 6.283185)
		new = 0;
 	game->player.angle = new;
}

double	new_angle(double num)
{
	double	new;
	double	aux;

	aux = num;
	while (aux >= 0)
		aux -= (2 * M_PI);
	aux += (2 * M_PI);
	new = aux;
	if (new == 6.23185)
		new = 0;
	return (new);
}

int	axis(double angle)
{
	if ((angle - 0) <= 0.0001
			|| ((angle - (M_PI / 2)) <= 0.001 && (angle - (M_PI / 2)) >= -0.001) 
			|| ((angle - (M_PI)) <= 0.001 && (angle - (M_PI)) >= -0.001) 
			|| ((angle - (3 * M_PI / 2)) <= 0.001 && (angle - (3 * M_PI / 2)) >= -0.001) 
			|| ((angle - (2 * M_PI)) <= 0.001 && (angle - (2 * M_PI)) >= -0.001))
		return (1);
	return (0);
}

void	looking_at(t_game *game)
{
	if (axis(game->player.angle))
		game->player.looking_at = 0; //axis
	else if ((game->player.angle > 0) && (game->player.angle < M_PI / 2))
		game->player.looking_at = 2; //abajo derecha
	else if ((game->player.angle > M_PI / 2) && (game->player.angle < M_PI))
		game->player.looking_at = 3; //abajo izquierda
	else if ((game->player.angle > M_PI) && (game->player.angle < 3 * M_PI / 2))
		game->player.looking_at = 4; //arriba izquierda
	else if ((game->player.angle > 3 * M_PI / 2) && (game->player.angle <  2 * M_PI))
		game->player.looking_at = 1; //arriba derecha
	/*
	else
	{
		if (axis(game->player.angle))
			game->player.looking_at = 0; //axis
	} 
	*/
}

void	ray_at(t_game *game, int r)
{
	if (axis(game->ray[r].ray_angle))
		game->ray[r].ray_at = 0; //axis
	else if ((game->ray[r].ray_angle > 0) && (game->ray[r].ray_angle < M_PI / 2))
		game->ray[r].ray_at = 2;
	else if ((game->ray[r].ray_angle > M_PI / 2) && (game->ray[r].ray_angle < M_PI))
		game->ray[r].ray_at = 3;
	else if ((game->ray[r].ray_angle > M_PI) && (game->ray[r].ray_angle <  3 * M_PI / 2))
		game->ray[r].ray_at = 4;
	else if ((game->ray[r].ray_angle > 3 * M_PI / 2) && (game->ray[r].ray_angle < 2 * M_PI))
		game->ray[r].ray_at = 1;
	/*
	else
	{
		if (axis(game->ray[r].ray_angle))
			game->player.looking_at = 0; //axis
	}
	*/
}



	
