/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:33:35 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/10 17:05:26 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Normalizar el angulo (que esté en el primer giro siempre)
void	angle(t_game *game)
{
	double	new;
	double	num;

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

int	is_angle(float angle, float angle_2)
{
	int	new_angle;
	int	testing;

	new_angle = angle * 1000000;
	testing = angle_2 * 1000000;
	if (new_angle == testing)
		return (1);
	return (0);
}
