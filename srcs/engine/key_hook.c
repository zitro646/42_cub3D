/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:36:49 by potero            #+#    #+#             */
/*   Updated: 2022/09/07 16:17:00 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	advance(int key_code, t_game *game)
{
	if (key_code == 53)
		close_esc(&game->mlx);
	else if (key_code == 13)
		game->player.advance = 1;
	else if (key_code == 1)
		game->player.advance = -1;
	else if (key_code == 0)
		game->player.advance = -1;
	else if (key_code == 2)
		game->player.advance = 1;
	else if (key_code == 123)
		game->player.turn = -1;
	else if (key_code == 124)
		game->player.turn = 1;
	hook(game, key_code);
	return (0);
}

int	stop(int key_code, t_game *game)
{
	if (key_code == 1 || key_code == 2 || key_code == 3 || key_code == 13)
	{
		game->player.advance = 0;
		printf("stop advance\n");
	}
	else if (key_code == 123 || key_code == 124)
		game->player.turn = 0;
	hook(game, key_code);
	return (0);
}

int	movement(t_game *game, double x, double y)
{
	if (x - (int)x >= 0.5)
		x = x + 1;
	if (y - (int)y >= 0.5)
		y = y + 1;
	if (game->matrix[(int)x][(int)y].value == '1')
	{
		printf("Impossible movement\n");
		return (1);
	}
	return (0);
}

void	hook(t_game *game, int key_code)
{
	double	new_x;
	double	new_y;

	if (key_code == 13 || key_code == 1)
	{
		new_y = (game->player.advance * (cos(game->player.angle) * game->player.speed_m)) 
			+ game->player.y;
		new_x = (game->player.advance * (sin(game->player.angle) * game->player.speed_m)) 
			+ game->player.x;
	}
	else if (key_code == 2 ||key_code == 0)
	{
		new_y = (game->player.advance * (cos(game->player.angle + (90 * M_PI / 180))
					* game->player.speed_m)) + game->player.y;
		new_x = (game->player.advance * (sin(game->player.angle + (90 * M_PI / 180))
					* game->player.speed_m)) + game->player.x;
	}
	else
	{
		new_x = game->player.x;
		new_y = game->player.y;
	}
	game->player.angle += game->player.turn * game->player.speed_t;
	if (game->player.angle > (2 * M_PI) || game->player.angle < 0)
		angle(game);
	printf("________________________\n");
	printf("Pos : [%f][%f]\n", new_x, new_y);
	printf("angle: %f\n", game->player.angle);
	looking_at(game);
	printf("looking at: %d\n", game->player.looking_at);
	printf("________________________\n");
	ray(game);
	if (movement(game, new_x, new_y) == 0)
	{
		image(game);
		game->player.x = new_x;
		game->player.y = new_y;
		player_pixel(game, 0xFF0000);
	}
}
