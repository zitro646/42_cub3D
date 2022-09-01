/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:10:03 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/01 12:33:52 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_event_n(int key_code, t_game *game)
{
	if (key_code == 0)
		if (movement(game, 0, -1) == 0)
			looking_at(game);
	if (key_code == 1)
		if (movement(game, 1, 0) == 0)
			looking_at(game);
	if (key_code == 2)
		if (movement(game, 0, 1) == 0)
			looking_at(game);
	if (key_code == 13)
		if (movement(game, -1, 0) == 0)
			looking_at(game);
	if (key_code == 123)
		look_left(game);
	if (key_code == 124)
		look_right(game);
	return (0);
}

int key_event_s(int key_code, t_game *game)
{
	if (key_code == 0)
		if (movement(game, 0, 1) == 0)
			looking_at(game);
	if (key_code == 1)
		if (movement(game, -1, 0) == 0)
			looking_at(game);
	if (key_code == 2)
		if (movement(game, 0, -1) == 0)
			looking_at(game);
	if (key_code == 13)
		if (movement(game, 1, 0) == 0)
			looking_at(game);
	if (key_code == 123)
		look_left(game);
	if (key_code == 124)
		look_right(game);
	return (0);
}

int key_event_e(int key_code, t_game *game)
{
	if (key_code == 0)
		if (movement(game, -1, 0) == 0)
			looking_at(game);
	if (key_code == 1)
		if (movement(game, 0, -1) == 0)
			looking_at(game);
	if (key_code == 2)
		if (movement(game, 1, 0) == 0)
			looking_at(game);
	if (key_code == 13)
		if (movement(game, 0, 1) == 0)
			looking_at(game);
	if (key_code == 123)
		look_left(game);
	if (key_code == 124)
		look_right(game);
	return (0);
}

int key_event_o(int key_code, t_game *game)
{
	if (key_code == 0)
		if (movement(game, 1, 0) == 0)
			looking_at(game);
	if (key_code == 1)
		if (movement(game, 0, 1) == 0)
			looking_at(game);
	if (key_code == 2)
		if (movement(game, -1, 0) == 0)
			looking_at(game);
	if (key_code == 13)
		if (movement(game, 0, -1) == 0)
			looking_at(game);
	if (key_code == 123)
		look_left(game);
	if (key_code == 124)
		look_right(game);
	return (0);
}
