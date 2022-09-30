/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:36:49 by potero            #+#    #+#             */
/*   Updated: 2022/09/30 17:55:51 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void test(t_game *game, t_image *test, int y_dis , int x_dis)
{
	int f;
	int c;

	f = 0;
	printf("Test\n");
	while(f < test->n_files)
	{
		c = 0;
		
		while (c < test->n_colums)
		{
			// printf("f = %d , c = %d\n",f,c);
			mlx_pixel_put(game->mlx.mlx, game->mlx.window, f+y_dis, c+x_dis, test->color_values[(f * 15) + c]);
			c++;
			
		}
		f++;
	}
	f--;
	printf("Last value of chain is %d\n",test->color_values[(f * 15) + c]);
	printf("Last value on chain is %d\n",test->color_values[(f * 15) + c]);
	return;
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
/*	if (f - (int)f >= 0.5)
		f = f + 1;
	if (c - (int)c >= 0.5)
		c = c + 1;
*/
	if (game->matrix[(int)f][(int)c].value == '1')
	{
		printf("Impossible movement\n");
		return (1);
	}
	if (game->player.looking_at == 1)
	{
		if ((game->matrix[(int)f][(int)c - 1].value == '1')
				&&(game->matrix[(int)f + 1][(int)c].value == '1'))
			return (1);
	}
  	if (game->player.looking_at == 2)
	{
		if ((game->matrix[(int)f - 1][(int)c].value == '1')
				&&(game->matrix[(int)f][(int)c - 1].value == '1'))
			return (1);
	}
	if (game->player.looking_at == 3)
	{
		if ((game->matrix[(int)f - 1][(int)c].value == '1')
				&&(game->matrix[(int)f][(int)c + 1].value == '1'))
			return (1);
	}
	if (game->player.looking_at == 4)
	{
		if ((game->matrix[(int)f + 1][(int)c].value == '1')
				&&(game->matrix[(int)f][(int)c + 1].value == '1'))
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

	printf("________________________\n");
	printf("Pos : [%f][%f]\n", new_f, new_c);
	printf("angle: %f\n", game->player.angle);
	looking_at(game);
//	printf("looking at: %d\n", game->player.looking_at);
	printf("________________________\n");

	if (movement(game, new_f - 0.5, new_c - 0.5) == 0)
	{
		wall_floor_pixel(game, game->player.f, game->player.c, 0x8C8C8C);
		game->player.f = new_f;
		game->player.c = new_c;
	}
	ray(game);
	player_pixel(game, 0x0000FF, game->player.f, game->player.c);
	ray_vision_dda_v2(game,game->player.angle);
	test(game, game->n_wall,0,0);
// 	test(game, game->s_wall,15,0);
// 	test(game, game->w_wall,0,15);
// 	test(game, game->e_wall,15,15);
}
