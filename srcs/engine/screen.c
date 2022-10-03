/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:07:53 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/03 14:35:05 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	screen_game(t_game *game)
{
	int		x;
	int		y;
	int		start;
	int		end;
	double	middle;

	middle = game->height / 2;
	x = 0;
	while ( x < game->width)
	{
		y = -1;
		start = middle - (game->ray[x].wall / 2);
		end = start + (int) game->ray[x].wall;
		while (y++ <= start)
			mlx_pixel_put(game->mlx.mlx, game->mlx.screen, x, y, 0xFF0000);
		y--;
		while (y++ < end)
			mlx_pixel_put(game->mlx.mlx, game->mlx.screen, x, y, 0xFFFF00);
		y--;
		while (y++ < game->height)
			mlx_pixel_put(game->mlx.mlx, game->mlx.screen, x, y, 0x4B0082);
		x++;
	}
}

int paint_line(t_game *game,t_image *image,int r, int y , int end)
{
	(void)image;

	float ty;
	float ty_step;
	ty = 0;
	ty_step = image->n_colums / (float) (end - y);
	
	while (y < end)
	{
		mlx_pixel_put(game->mlx.mlx, game->mlx.screen, r, y, image->color_values[(game->ray[r].pixel_hit * image->n_colums) + (int)ty]);
		y++;
		ty +=ty_step;
	}
	
	return (y);
}

int draw_line(t_game *game,int r, int y, int end)
{
	if (game->ray[r].side_hit == HORIZONTAL_HIT)
	{
		if ( game->ray[r].ray_angle > M_PI)
			y = paint_line(game,game->n_wall,r,y,end);
		else
			y = paint_line(game,game->s_wall,r,y,end);
	}
	else
	{
		if ( game->ray[r].ray_angle > M_PI / 2 && game->ray[r].ray_angle < (3 * M_PI) / 2)
			y = paint_line(game,game->e_wall,r,y,end);
		else
			y = paint_line(game,game->w_wall,r,y,end);
	}
	
	return (y);
}

// if (game->ray[r].side_hit == HORIZONTAL_HIT)
// 	{
// 		if ( game->ray[r].ray_angle > M_PI)
// 			while (y++ < end)
// 				mlx_pixel_put(game->mlx.mlx, game->mlx.screen, r, y, PURPLE);
// 		else
// 			while (y++ < end)
// 				mlx_pixel_put(game->mlx.mlx, game->mlx.screen, r, y, BLUE);
// 	}
// 	else
// 	{
// 		if ( game->ray[r].ray_angle > M_PI / 2 && game->ray[r].ray_angle < (3 * M_PI) / 2)
// 			while (y++ < end)
// 				mlx_pixel_put(game->mlx.mlx, game->mlx.screen, r, y, DARK_PURPLE);
// 		else
// 			while (y++ < end)
// 				mlx_pixel_put(game->mlx.mlx, game->mlx.screen, r, y, CYAN);
// 	}


void	screen_game_r(t_game *game, int r)
{
	int		y;
	int		start;
	int		end;
	double	middle;

	middle = game->height / 2;
	y = -1;
	start = middle - (game->ray[r].wall / 2);
	end = start + (int)game->ray[r].wall;
	while (y++ <= start)
		mlx_pixel_put(game->mlx.mlx, game->mlx.screen, r, y, game->roof_colour);
	y--;
	y = draw_line(game, r, y, end);
	y--;
	while (y++ < game->height)
		mlx_pixel_put(game->mlx.mlx, game->mlx.screen, r, y, game->floor_colour);
}

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
		y = -1;
		while (++y < middle)
			mlx_pixel_put(game->mlx.mlx, game->mlx.screen, x, y, game->roof_colour);
		y--;
		while (y++ < game->height)
			mlx_pixel_put(game->mlx.mlx, game->mlx.screen, x, y, game->floor_colour);
	}
	mlx_string_put(game->mlx.mlx, game->mlx.screen, (game->width / 2) - 50,
			(game->height / 2) - 30, 0xFFFF00, string);
}	
