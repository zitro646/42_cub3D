/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:36:49 by potero            #+#    #+#             */
/*   Updated: 2022/10/11 12:59:55 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	advance(int key_code, t_game *game)
{
	if (key_code == 53)
		return (close_esc(game));
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

int	movement(t_game *game, double f, double c)
{
	int	player_c;
	int	player_f;

	player_c = game->player.c;
	player_f = game->player.f;
	if (game->matrix[(int)f][(int)c].value == '1')
	{
		printf("Impossible movement\n");
		return (1);
	}
	else if (game->matrix[player_f][(int)c].value == '1'
				&& game->matrix[(int)f][player_c].value == '1')
	{
		printf("Impossible movement\n");
		return (1);
	}
	return (0);
}

void	hook(t_game *game, int key_code)
{
	double	new_f;
	double	new_c;

	if (key_code == 13 || key_code == 1)
	{
		new_c = (game->player.advance * (cos(game->player.angle)
					* game->player.speed_m)) + game->player.c;
		new_f = (game->player.advance * (sin(game->player.angle)
					* game->player.speed_m)) + game->player.f;
	}
	else if (key_code == 2 || key_code == 0)
	{
		new_c = (game->player.advance * (cos(game->player.angle + (M_PI / 2))
					* game->player.speed_m)) + game->player.c;
		new_f = (game->player.advance * (sin(game->player.angle + (M_PI / 2))
					* game->player.speed_m)) + game->player.f;
	}
	else
	{
		new_f = game->player.f;
		new_c = game->player.c;
	}
	new_c = (int)new_c + 0.5;
	new_f = (int)new_f + 0.5;
	finish_hook(new_c, new_f, game);
}

void	finish_hook(double new_c, double new_f, t_game *game)
{
	game->player.angle += game->player.turn * game->player.speed_t;
	if (game->player.angle > (2 * M_PI) || game->player.angle < 0)
		angle(game);
	if (movement(game, new_f - 0.5, new_c - 0.5) == 0)
	{
		game->player.f = new_f;
		game->player.c = new_c;
	}
	ray(game);
	frame(game);
	minimap(game);
}
