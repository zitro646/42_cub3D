/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:52:30 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/12 14:23:01 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pos_is_wall( int x_pixel, int y_pixel, t_game *game)
{
	int	x;
	int	y;

	x = x_pixel / 15;
	y = y_pixel / 15;
	//printf("pos in matrix -> x : %i , y : %i\n", x, y);
	if (game->matrix[y][x].value == '1')
	{
		return (1);
	}
	//printf("No toque un muro :(\n");
	// printf("pos in matrix pixel -> x : %i , y : %i\n", x_pixel, y_pixel);
	// printf("pos in matrix -> x : %i , y : %i\n", x, y);
	return (0);
}

void	draw_vision_line(t_game *game, int color, double angle)
{
	double	line;
	int		i;
	int		j;

	line = 0;
	j = (game->player.y * 15) + (cos(angle) * line);
	i = (game->player.x * 15) + (sin(angle) * line);
	while (line < 15)
	{
		j = (game->player.y * 15) + (cos(angle) * line);
		i = (game->player.x * 15) + (sin(angle) * line);
		mlx_pixel_put(game->mlx.mlx, game->mlx.window,
			j, i, color);
		line += 0.3;
	}
}

void	player_vision_cone(t_game *game, int color)
{
	// ray_vision(game, 0x0000FF, 0);
	ray_vision_dda(game, color, 0);
	// //ray_vision(game, 0x0000FF, 0);
	// // ray_vision(game, color, M_PI / 4);
	// // ray_vision(game, color, - M_PI / 4);
	return ;
}

	
void	player_pixel(t_game *game, int color)
{
	int		i;
	int		j;

	i = -2;
	while (i < 3)
	{
		j = -2;
		while (j < 3)
		{
			mlx_pixel_put(game->mlx.mlx, game->mlx.window,
				(game->player.y * 15) + j, (game->player.x * 15) + i, color);
			j++;
		}
		i++;
	}
	draw_vision_line(game,0xF00F0F,game->player.angle);
	// printf("%f - %f\n",game->player.pdx *15,game->player.pdy*15);
	// draw_new_line(game,game->player.x * 15,game->player.y* 15,game->player.pdx* 15 ,game->player.pdy * 15,0xF00F0F);
	player_vision_cone(game, color);
}	
//i = sin(game->player.angle) * line;
//j = cos(game->player.angle) * line;
void	wall_floor_pixel(t_game *game, int pos_x, int pos_y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 15)
	{
		j = 0;
		while (j < 15)
		{
			mlx_pixel_put(game->mlx.mlx, game->mlx.window,
				(pos_y * 15) + j, (pos_x * 15) + i, color);
			j++;
		}
		i++;
	}
}

void	image_aux(t_game *game, int pos_x, int pos_y)
{
	wall_floor_pixel(game, pos_x, pos_y, 0x8C8C8C);
	if (game->matrix[pos_x][pos_y].value == 'N')
	{
		game->player.x = pos_x + 0.5;
		game->player.y = pos_y + 0.5;
		player_pixel(game, 0X0000FF);
		game->player.angle = 3 * M_PI / 2;
		game->matrix[pos_x][pos_y].value = '0';
	}

	else if (game->matrix[pos_x][pos_y].value == 'S')
	{
		game->player.x = pos_x + 0.5;
		game->player.y = pos_y + 0.5;
		player_pixel(game, 0X0000FF);
		game->player.angle = (M_PI / 2);
		game->matrix[pos_x][pos_y].value = '0';
	}
	else if (game->matrix[pos_x][pos_y].value == 'O')
	{
		game->player.x = pos_x + 0.5;
		game->player.y = pos_y + 0.5;
		player_pixel(game, 0X0000FF);
		game->player.angle = M_PI;
		game->matrix[pos_x][pos_y].value = '0';
	}
	else if (game->matrix[pos_x][pos_y].value == 'E')
	{
		game->player.x = pos_x + 0.5;
		game->player.y = pos_y + 0.5;
		player_pixel(game, 0X0000FF);
		game->player.angle = 0;
		game->matrix[pos_x][pos_y].value = '0';
	}
}

void	image(t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = 0;
	while (pos_x < game->size_x)
	{
		pos_y = 0;
		while (pos_y < game->size_y)
		{
			if (game->matrix[pos_x][pos_y].value == '1')
				wall_floor_pixel(game, pos_x, pos_y, 0x4B0082);
			else if (game->matrix[pos_x][pos_y].value != '1')
			{
				image_aux(game, pos_x, pos_y);
			}
			pos_y++;
		}
		pos_x++;
	}
}
