/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:45:51 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/09/28 16:06:32 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// y - f = height || x - c = width
int draw_new_line(t_game *game, int beginX, int beginY, int endX, int endY, int color)
{
	double	deltaX; // 10
	double	deltaY; // 0
	double	pixelX;
	double	pixelY;
	int		pixels;

	deltaX = endX - beginX;
	deltaY = endY - beginY;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));;
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0
	pixelX = beginX;
	pixelY = beginY;
	while (pixels)
	{
		mlx_pixel_put(game->mlx.mlx, game->mlx.window, pixelY, pixelX, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return (0);
}

int	inside_matrix(t_game *game, int f, int c)
{
	if (f < game->size_f && f >= 0 && c < game->size_c && c >= 0)
	{
		return (1);
	}
	return (0);
}

float distance(float ax, float ay, float bx, float by)
{
	return (sqrt(((bx - ax) * (bx - ax)) + ((by - ay) * (by - ay))));
}

int	new_pos_is_wall( int y, int x, t_game *game)
{
	if (game->matrix[y][x].value == '1')
	{
		return (1);
	}
	return (0);
}

// y - c = height || x - f = width
double	ray_vision_dda(t_game *game, double angle)
{
	int dof;
	int mx,my;
	float rx,ry,xo,yo;

	//Checkeo horizontal
	dof = 0;
	float aTan = -1/tan(angle);
	float distH;
	float hx, hy;
	distH = (game->size_c * 30) * (game->size_f * 30);
	hx = game->player.c;
	hy = game->player.f;
//en caso de que el angulo sea perfecto hacia la izquierda o derecha
	if (angle == 0 || angle == M_PI)
	{
		hx = game->player.c * 30;
		hy = game->player.f * 30;
		dof = game->size_c * game->size_f;
	}
	else if (angle > M_PI)
	{
		ry = (((int)(game->player.f * 30) / 30 ) * 30 ) - 0.0001;
		rx = ((int)(game->player.f * 30) - ry) * aTan + game->player.c * 30;
		yo = -30;
		xo = -yo * aTan;
	}
	else if (angle < M_PI)
	{
		ry = (((int)(game->player.f * 30) / 30 ) * 30 ) + 30;
		rx = ((int)(game->player.f * 30) - ry) * aTan + game->player.c * 30;
		yo = 30;
		xo = -yo * aTan;
	}

	while (dof < (game->size_c * game->size_f))
	{
		my = ((int)ry) / 30;
		mx = ((int)rx) / 30;
		if (inside_matrix(game,my,mx))
		{
			if (new_pos_is_wall(my, mx, game))
			{
				dof = game->size_c * game->size_f;
				hx = rx;
				hy = ry;
				distH = distance(game->player.c * 30,game->player.f * 30,hx,hy);
			}
			else
			{
				rx += xo;
			 	ry += yo;
			 	dof++;
			}
		}
		else
		{
			dof = game->size_c * game->size_f;
		}

	}
	//__________________________________

	//Checkeo vertical
	dof = 0;
	float nTan = -tan(angle);
	float distV;
	float vx, vy;

	distV = (game->size_c * 30) * (game->size_f * 30);
	vx = game->player.c;
	vy = game->player.f;
//en caso de que el angulo sea perfecto hacia la arriba o abajo
	if (angle == M_PI/2 || angle == 3*M_PI/2)
	{
		vx = game->player.c * 30;
		vy = game->player.f * 30;
		dof = game->size_c * game->size_f;
	}
	else if (angle > M_PI / 2 && angle < (3 * M_PI) / 2)
	{
		rx = (((int)(game->player.c * 30) / 30 ) * 30 ) - 0.0001;
		ry = ((int)(game->player.c * 30) - rx) * nTan + game->player.f * 30;
		xo = -30;
		yo = -xo * nTan;
	}
	else if (angle < M_PI/2 || angle > 3*M_PI/2)
	{
		rx = (((int)(game->player.c * 30) / 30 ) * 30 ) + 30;
		ry = ((int)(game->player.c * 30) - rx) * nTan + game->player.f * 30;
		xo = 30;
		yo = -xo * nTan;
	}

	while (dof < (game->size_c * game->size_f))
	{
		my = ((int)ry) / 30;
		mx = ((int)rx) / 30;
		if (inside_matrix(game,my,mx))
		{
			if (new_pos_is_wall(my, mx, game))
			{
				dof = game->size_c * game->size_f;
				vx = rx;
				vy = ry;
				distV = distance(game->player.c * 30,game->player.f * 30,vx,vy);
			}
			else
			{
				rx += xo;
			 	ry += yo;
			 	dof++;
			}
		}
		else
		{
			dof = game->size_c * game->size_f;
		}

	}

	if (distV < distH)
	{
		rx = vx;
		ry = vy;
	}
	else
	{
		rx = hx;
		ry = hy;
	}

	// draw_new_line(game, game->player.f * 30,game->player.c * 30,ry,rx,WHITE);
	return (distance(game->player.c * 30,game->player.f * 30,rx,ry) / 30);
}
