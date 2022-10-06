/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:36:49 by potero            #+#    #+#             */
/*   Updated: 2022/10/06 00:49:28 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// //TOOL TO VISUALIZE
void	player_vision_cone(t_game *game)
{
	// int i;
	// double angle;

	// angle = game->player.angle;
	// i = 0;
	// while (i < 240)
	// {
	// 	ray_vision_dda_testing(game, angle, WHITE);
	// 	angle = new_angle (angle + game->diff_angle);
	// 	i++;
	// }
	// i = 0;
	// angle = new_angle (game->player.angle);
	// while (i < 240)
	// {
	// 	ray_vision_dda_testing(game, angle, WHITE);
	// 	angle = new_angle (angle - game->diff_angle);
	// 	i++;
	// }
	ray_vision_dda_testing (game,game->player.angle,RED);
	return ;
}


int	advance(int key_code, t_game *game)
{
	if (key_code == 53)
		close_esc(game);
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
	else if (key_code == 2 ||key_code == 0)
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
	game->player.angle += game->player.turn * game->player.speed_t;
	if (game->player.angle > (2 * M_PI) || game->player.angle < 0)
		angle(game);

	looking_at(game);

	if (movement(game, new_f - 0.5, new_c - 0.5) == 0)
	{
		game->player.f = new_f;
		game->player.c = new_c;
	}
	ray(game);
	minimap(game);
	mlx_clear_window(game->mlx.mlx, game->mlx.window);
	window(game, 1);
	player_vision_cone(game);
	// ray_vision_dda_testing(game,game->player.angle,0);
}
