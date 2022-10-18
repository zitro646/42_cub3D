/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:46:07 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/10/18 12:46:34 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	start_game(t_game *game)
{
	int		middle;
	int		x;
	int		y;
	char	*string;

	string = "PRESS A KEY";
	middle = game->height / 2;
	y = 0;
	x = -1;
	while (++x < game->width)
	{
		y = 0;
		while (++y < middle)
			put_pixel(&game->scrn, x, y, game->roof_color);
		while (++y < game->height)
			put_pixel(&game->scrn, x, y, game->floor_color);
	}
	mlx_put_image_to_window(game->mlx.mlx,
		game->mlx.screen, game->scrn.image, 0, 0);
	mlx_string_put(game->mlx.mlx, game->mlx.screen,
		(game->width / 2) - 50, (game->height / 2) - 30, 0x00FF00, string);
}	