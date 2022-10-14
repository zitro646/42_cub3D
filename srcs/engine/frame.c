/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:12:27 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/11 13:25:26 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	left_frame(t_game *game, int c)
{
	int	f;

	f = 0;
	while (f < game->height)
	{
		put_pixel(&game->scrn, c, f, DARK_GREEN);
		f++;
	}
	c++;
	return (c);
}

int	right_frame(t_game *game, int c)
{
	int	f;

	f = 0;
	while (f < game->height)
	{
		put_pixel(&game->scrn, c, f, DARK_GREEN);
		f++;
	}
	c++;
	return (c);
}

void	frame(t_game *game)
{
	int	c;
	int	f;

	c = 0;
	while (c < 5)
		c = left_frame(game, c);
	while (c < game->width -5)
	{
		f = 0;
		while (f < 5)
		{
			put_pixel(&game->scrn, c, f, DARK_GREEN);
			f++;
		}
		while (f < game->height - 5)
			f++;
		while (f < game->height)
		{
			put_pixel(&game->scrn, c, f, DARK_GREEN);
			f++;
		}
		c++;
	}
	while (c < game->width)
		c = right_frame(game, c);
}
