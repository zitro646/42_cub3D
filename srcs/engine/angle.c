/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:33:35 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/09 10:41:19 by potero           ###   ########.fr       */
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
	return (new);
}

void	looking_at(t_game *game)
{
	if ((game->player.angle > 0) && (game->player.angle < M_PI / 2))
		game->player.looking_at = 2; //abajo derecha
	else if ((game->player.angle > M_PI / 2) && (game->player.angle < M_PI))
		game->player.looking_at = 3; //abajo izquierda
	else if ((game->player.angle > M_PI) && (game->player.angle < 3 * M_PI / 2))
		game->player.looking_at = 4; //arriba izquierda
	else if ((game->player.angle > 3 * M_PI / 2) && (game->player.angle <  2 * M_PI))
		game->player.looking_at = 1; //arriba derecha
}

void	ray_at(t_game *game)
{
	int	r;

	r = 0;
	while (r < game->width)
	{
		if ((game->ray[r].ray_angle > 0) && (game->ray[r].ray_angle < M_PI / 2))
			game->ray[r].ray_at = 2;
		else if ((game->ray[r].ray_angle > M_PI / 2) && (game->ray[r].ray_angle < M_PI))
			game->ray[r].ray_at = 3;
		else if ((game->ray[r].ray_angle > M_PI) && (game->ray[r].ray_angle <  3 * M_PI / 2))
			game->ray[r].ray_at = 4;
		else if ((game->ray[r].ray_angle > 3 * M_PI / 2) && (game->ray[r].ray_angle < 2 * M_PI))
			game->ray[r].ray_at = 1;
		r++;
	}
};



	
