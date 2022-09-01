/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:21:37 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/01 12:34:29 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_event(int key_code, t_game *game)
{
	if (key_code == 53)
		 close_esc(&game->mlx);
	if (game->direction == 1)
		key_event_n(key_code, game);
	else if (game->direction == 2)
		key_event_e(key_code, game);
	else if (game->direction == 3)
		key_event_s(key_code, game);
	else if (game->direction == 4)
		key_event_o(key_code, game);
	return (0);
}

int	movement(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + x;
	new_y = game->player.y + y;
	if (game->matrix[new_x][new_y].value == '1')
	{
		printf("Impossible movement\n");
		return (1);
	}
	else
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window, game->mlx.img_f,
			((game->player.y) * 15), ((game->player.x) * 15));
		game->player.x = new_x;
		game->player.y = new_y;
		return (0);
	}
}
