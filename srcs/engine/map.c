/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:52:30 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/22 03:02:54 by mortiz-d         ###   ########.fr       */
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

void	ray_vision(t_game *game, int color, double angle)
{
	double	line;
	int		i;
	int		j;

	line = 0;
	j = ((game->player.y - 0.5) * 15) + (cos(game->player.angle) * line) + 7;
	i = ((game->player.x - 0.5) * 15) + (sin(game->player.angle) * line) + 7;
	while (!pos_is_wall(j, i, game))
	{
		j = ((game->player.y - 0.5) * 15) + (cos(game->player.angle + angle) * line) + 7;
		i = ((game->player.x - 0.5) * 15) + (sin(game->player.angle + angle) * line) + 7;
		pos_is_wall(j, i, game);
		mlx_pixel_put(game->mlx.mlx, game->mlx.window,
			j, i, color);
		line += 0.1;
	}
}


void	player_vision_cone(t_game *game, int color)
{
	int i;
	double angle;

	i = 0;
	angle = new_angle (game->player.angle);
	while (i < 240)
	{
		ray_vision_dda(game, WHITE, angle);
		angle = new_angle (angle + game->diff_angle);
		i++;
	}
	i = 0;
	angle = new_angle (game->player.angle);
	while (i < 240)
	{
		ray_vision_dda(game, WHITE, angle);
		angle = new_angle (angle - game->diff_angle);
		i++;
	}
	ray_vision_dda (game,color,game->player.angle);
	// ray_vision(game,BLUE,game->player.angle);
	return ;
}

void	player_pixel(t_game *game, int color)
{
	int		i;
	int		j;

	i = 5;
	while (i < 10)
	{
		j = 5;
		while (j < 10)
		{
			mlx_pixel_put(game->mlx.mlx, game->mlx.window,
				((game->player.y - 0.5) * 15) + j, ((game->player.x - 0.5) * 15) + i, color);
			j++;
		}
		i++;
	}
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
	double	aux;

	aux = 0.5;
	wall_floor_pixel(game, pos_x, pos_y, 0x8C8C8C);
	if (game->matrix[pos_x][pos_y].value == 'N')
	{
		game->player.x = pos_x + aux;
		game->player.y = pos_y + aux;
		game->player.angle = 3 * M_PI / 2;
		player_pixel(game, 0X0000FF);
		game->matrix[pos_x][pos_y].value = '0';
	}

	else if (game->matrix[pos_x][pos_y].value == 'S')
	{
		game->player.x = pos_x + aux;
		game->player.y = pos_y + aux;
		game->player.angle = (M_PI / 2);
		player_pixel(game, 0X0000FF);
		game->matrix[pos_x][pos_y].value = '0';
	}
	else if (game->matrix[pos_x][pos_y].value == 'O')
	{
		game->player.x = pos_x  + aux ;
		game->player.y = pos_y + aux;
		game->player.angle = M_PI;
		player_pixel(game, 0X0000FF);
		game->matrix[pos_x][pos_y].value = '0';
	}
	else if (game->matrix[pos_x][pos_y].value == 'E')
	{
		game->player.x = pos_x + aux;
		game->player.y = pos_y + aux;
		game->player.angle = 0;
		player_pixel(game, 0X0000FF);
		game->matrix[pos_x][pos_y].value = '0';
	}
}

void	image(t_game *game)
{
	int	pos_x;
	int	pos_y;
	int max_y;
	int max_x;

	pos_x = 0;
	max_y = game->size_x;
	max_x = game->size_y;
	while (pos_x < game->size_y)
	{
		pos_y = 0;
		while (pos_y < game->size_x)
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
