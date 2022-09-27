/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:52:30 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/27 16:27:44 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pos_is_wall( int x_pixel, int y_pixel, t_game *game)
{
	int	x;
	int	y;

	//printf("pos in matrix -> x : %i , y : %i\n", x_pixel, y_pixel);
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

void	ray_vision(t_game *game, int color)
{
	double	line;
	int		i;
	int		j;

	line = 5;
	/*
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
	*/
	j = (game->player.c - 0.5) * 30 + 15;
	i = (game->player.f - 0.5) * 30 + 15;
	while (line < 10)
	{
		mlx_pixel_put(game->mlx.mlx, game->mlx.window,
				j + (cos(game->player.angle) * line),
				i + (sin(game->player.angle) * line), color);
		line += 0.2;
	}
//	hit_pixel(game, 0);
	hit_pixel(game, 275, 0xF4D03F, 0xFFEB3B); // yellow
	hit_pixel(game, 375, 0x1D8348, 0x1D8348); //green
	hit_pixel(game, 475, 0xE74C3C, 0xE74C3C); //red
//	hit_pixel(game, 749);
}

/*
void	player_vision_cone(t_game *game, int color)
{
	ray_vision(game, color, 0);
	ray_vision(game, color, M_PI / 4);
	ray_vision(game, color, - M_PI / 4);
	return ;
}
*/
void	player_pixel(t_game *game, int color)
{
	int		i;
	int		j;

	i = 10;
	while (i < 20)
	{
		j = 10;
		while (j < 20)
		{
		//	mlx_pixel_put(game->mlx.mlx, game->mlx.screen, 910 + j, 910 + i, color);
			mlx_pixel_put(game->mlx.mlx, game->mlx.window,
				((game->player.c - 0.5) * 30) + j, ((game->player.f - 0.5) * 30) + i, color);
			j++;
		}
		i++;
	}
	ray_vision(game, color);
//	player_vision_cone(game, color);
}	

void	wall_floor_pixel(t_game *game, int pos_f, int pos_c, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 30)
	{
		j = 0;
		while (j < 30)
		{
			if (i == 0 || j == 0)
				mlx_pixel_put(game->mlx.mlx, game->mlx.window,
					((pos_c * 30) + j), ((pos_f * 30 ) + i), 0x000000);
			else
				mlx_pixel_put(game->mlx.mlx, game->mlx.window,
					((pos_c * 30) + j), ((pos_f * 30 ) + i), color);
			j++;
		}
		i++;
	}
}

void	image_aux(t_game *game, int pos_f, int pos_c)
{
	double	aux;

	aux = 0.5;
	wall_floor_pixel(game, pos_f, pos_c, 0x8C8C8C);
	if (game->matrix[pos_f][pos_c].value == 'N')
	{
		game->player.f = pos_f + aux;
		game->player.c = pos_c + aux;
		game->player.angle = 3 * M_PI / 2;
		player_pixel(game, 0X0000FF);
		game->matrix[pos_f][pos_c].value = '0';
	}

	else if (game->matrix[pos_f][pos_c].value == 'S')
	{
		game->player.f = pos_f + aux;
		game->player.c = pos_c + aux;
		game->player.angle = (M_PI / 2);
		player_pixel(game, 0X0000FF);
		game->matrix[pos_f][pos_c].value = '0';
	}
	else if (game->matrix[pos_f][pos_c].value == 'O')
	{
		game->player.f = pos_f  + aux ;
		game->player.c = pos_c + aux;
		game->player.angle = M_PI;
		player_pixel(game, 0X0000FF);
		game->matrix[pos_f][pos_c].value = '0';
	}
	else if (game->matrix[pos_f][pos_c].value == 'E')
	{
		game->player.f = pos_f + aux;
		game->player.c = pos_c + aux;
		game->player.angle = 0;
		player_pixel(game, 0X0000FF);
		game->matrix[pos_f][pos_c].value = '0';
	}
}

void	image(t_game *game)
{
	int	pos_f;
	int	pos_c;

	pos_f = 0;
	while (pos_f < game->size_f)
	{
		pos_c = 0;
		while (pos_c < game->size_c)
		{
			if (game->matrix[pos_f][pos_c].value == '1')
				wall_floor_pixel(game, pos_f, pos_c, 0x4B0082);
			// else if (game->matrix[pos_x][pos_y].value != '1')
			else if (game->matrix[pos_f][pos_c].value != '1')
			{
				image_aux(game, pos_f, pos_c);
			}
			pos_c++;
		}
		pos_f++;
	}
}
/*
void	minimap(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 0;
	i = game->player.x;
	i -= 5;
	j = game->player.y;
	j -= 5;
	while (x < 11)
	{
		y = 0;
		while (y < 11)
		{
			if ((i + x) < 0 || (i + x) >= game->size_x || (j + y) < 0 || (j + y) >= game->size_y)
				wall_floor_pixel(game, 835 + 15 * x, 835 + 15 * y, 0x000000);
			else if (game->matrix[i + x][j + y].value == '1')
				wall_floor_pixel(game, 835 + 15 * x, 835 + 15 * y, 0x27AE60);
			else if (game->matrix[i + x][j + y].value != '1')
				wall_floor_pixel(game, 835 + 15 * x, 835 + 15 * y, 0xDC7633);
			y++;
		}
		x++;
	}
//	player_pixel(game, 0X0000FF);
}
*/



