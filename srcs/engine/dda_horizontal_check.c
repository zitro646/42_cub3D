/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_horizontal_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 01:01:02 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/09/22 03:04:20 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	horizontal_check(int my, int mx, float  angle, t_game *game)
{
	if (angle > M_PI / 2 && angle < (3 * M_PI) / 2)
	{
		if (new_pos_is_wall(my,mx, game) || new_pos_is_wall(my,mx + 1, game)) // 
		{
			return  (1);
		}
	}
	else if (angle < M_PI/2 || angle > 3*M_PI/2)
	{	
		if (new_pos_is_wall(my,mx, game) || new_pos_is_wall(my,mx - 1, game)) // 
		{
			return  (1);
		}
	}	
	return (0);
}

void correct_horizontal_hit(float *pixel_y, float *pixel_x, float angle,t_game *game)
{
	int my;
	int mx;
	(void)angle;
	
	my = ((int)*pixel_x) / 15;
	mx = ((int)*pixel_y) / 15;
	if (!new_pos_is_wall(my,mx, game))
	{
		centralize_hit_point(pixel_y, pixel_x, angle, game);
		// if (angle < (3 * (M_PI/2)) && angle > (M_PI/2))
		// 	*pixel_y = *pixel_y + 1;
		// else
		// 	*pixel_y = *pixel_y - 1;
	}
	return ;
}