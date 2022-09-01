/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:52:30 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/01 14:28:55 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_pixel(t_game *game)
{
	int	i;
	int	j;

	i = 5;
	j = 6;
	while (i < 10)
	{
		j = 6;
		while (j < 11)
		{
			mlx_pixel_put(game->mlx.mlx, game->mlx.window,
				(game->player.y * 15) + j, (game->player.x * 15) + i, 0x00FF0000);
			j++;
		}
		i++;
	}
}	
	

void	image_aux(t_game *game, int pos_x, int pos_y)
{
	if (game->matrix[pos_x][pos_y].value == '0')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
			game->mlx.img_f, (pos_y * 15), (pos_x * 15));
	else if (game->matrix[pos_x][pos_y].value == 'N')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
			game->mlx.img_n, (pos_y * 15), (pos_x * 15));
		game->player.x = pos_x;
		game->player.y = pos_y;
		game->direction = dir(game->matrix[pos_x][pos_y].value);
		player_pixel(game);
	}
	else if (game->matrix[pos_x][pos_y].value == 'S')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
			game->mlx.img_s, (pos_y * 15), (pos_x * 15));
		game->player.x = pos_x;
		game->player.y = pos_y;
		game->direction = dir(game->matrix[pos_x][pos_y].value);
	}
	else if (game->matrix[pos_x][pos_y].value == 'O')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
			game->mlx.img_o, (pos_y * 15), (pos_x * 15));
		game->player.x = pos_x;
		game->player.y = pos_y;
		game->direction = dir(game->matrix[pos_x][pos_y].value);
	}
	else if (game->matrix[pos_x][pos_y].value == 'E')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
			game->mlx.img_e, (pos_y * 15), (pos_x * 15));
		game->player.x = pos_x;
		game->player.y = pos_y;
		game->direction = dir(game->matrix[pos_x][pos_y].value);
	}
}

void	image(t_game *game, int x, int y)
{
	int	pos_x;
	int	pos_y;

	pos_x = 0;
	pos_y = 0;
	while (pos_x < x)
	{
		//printf("Veces llamado [%i] \n",pos_y);
		pos_y = 0;
		while (pos_y < y)
		{
			// printf("casilla[%i][%i] = %c \n",pos_x, pos_y, game->matrix[pos_x][pos_y].value);
			if (game->matrix[pos_x][pos_y].value == '1')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.window,
					game->mlx.img_w, (pos_y * 15), (pos_x * 15));
			else if (game->matrix[pos_x][pos_y].value != '1')
			{
				image_aux(game, pos_x, pos_y);
			}
			pos_y++;
		}
		printf("\n");
		pos_x++;
	}
}
