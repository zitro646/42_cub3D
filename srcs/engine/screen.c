/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:07:53 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/04 11:50:47 by potero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	select_texture(t_game *game, int r)
{
	if (game->ray[r].hit_vertical == 1)
	{
		if (game->ray[r].ray_angle > (M_PI / 2) && game->ray[r].ray_angle < (3 * M_PI / 2))
			return (3);
		else
			return (1);
	}
	else if (game->ray[r].hit_horizontal == 1)
	{
		if (game->ray[r].ray_angle > 0 && game->ray[r].ray_angle < M_PI)
			return (2);
		else
			return (0);
	}
	return (0);
}

void	screen_game_r(t_game *game, int r)
{
	int			y;
	int			start;
	int			end;
	double		middle;
	double		step;
	unsigned int	color;
	int				index;
	double			c;
	int				t;

	t = select_texture(game, r);
	middle = game->height / 2;
	y = -1;
	start = middle - (game->ray[r].wall / 2);
	end = start + (int)game->ray[r].wall;
	step = 1.0 * game->texture[t].height / game->ray[r].wall;
	c = (start - middle + game->ray[r].wall / 2) * step;
	while (y++ <= start)
		put_pixel(&game->scrn, r, y, game->roof_color);
	y--;
	while (y++ < end)
	{
		index = (int)c * game->texture[t].width + game->ray[r].hit_c;
		c += step;
		color = ((unsigned int *)(game->texture[t].add))[index];
		put_pixel(&game->scrn, r, y, color);
	}
	y--;
	while (y++ < game->height)
		put_pixel(&game->scrn, r, y, game->floor_color);
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
			put_pixel(&game->scrn, x, y, game->roof_color);
		y--;
		while (y++ < game->height)
			put_pixel(&game->scrn, x, y, game->floor_color);
	}
	mlx_put_image_to_window(game->mlx.mlx,
			game->mlx.screen, game->scrn.image, 0, 0);
	mlx_string_put(game->mlx.mlx, game->mlx.screen,
			(game->width / 2) - 50, (game->height / 2) - 30, 0x00FF00, string);
}	
