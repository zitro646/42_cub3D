/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:45:51 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/09/22 19:19:38 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	inside_matrix(t_game *game, int y, int x)
{
	if (y < game->size_y && y >= 0 && x < game->size_x && x >= 0)
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

void centralize_hit_point(float *pixel_y, float *pixel_x, float angle,t_game *game)
{
	double	line;
	int		i;
	int		j;

	line = 0;
	angle = new_angle(angle + M_PI);
	j = (int)(*pixel_y) + (cos(angle) * line) ;
	i = (int)(*pixel_x) + (sin(angle) * line) ;
	// printf("pos in matrix -> x : %i , y : %i\n", j/15, i/15);
	while (!new_pos_is_wall(i / 15, j / 15, game))
	{
		j = (int)(*pixel_y) + (cos(angle) * line) ;
		i = (int)(*pixel_x) + (sin(angle) * line) ;
		if ( line >= 10)
			break;
		line += 0.1;
	}
	if (line < 10)
	{
		*pixel_x = (int)(*pixel_x) + (sin(angle) * line);
		*pixel_y = (int)(*pixel_y) + (cos(angle) * line);
	}
}

void bring_hit_to_closest_wall_point(float *pixel_y, float *pixel_x, float angle,t_game *game)
{
	double	line;
	int		i;
	int		j;

	line = 3;
	angle = new_angle(angle - M_PI);
	j = (int)(*pixel_y) + (cos(angle) * line) ;
	i = (int)(*pixel_x) + (sin(angle) * line) ;
	if (!new_pos_is_wall(i / 15, j / 15, game))
		return;
	while (new_pos_is_wall(i / 15, j / 15, game))
	{
		j = (int)(*pixel_y) + (cos(angle) * line) ;
		i = (int)(*pixel_x) + (sin(angle) * line) ;
		line += 0.25;
		
	}
	*pixel_x = (int)(*pixel_x) + (sin(angle) * line - 0.25);
	*pixel_y = (int)(*pixel_y) + (cos(angle) * line - 0.25);
}


double	ray_vision_dda(t_game *game, int color, double angle)
{
	(void)game;
	(void)color;
	int dof;
	int mx,my;
	float rx,ry,xo,yo;
	float ra;
	ra = new_angle( angle - (3*M_PI/2));
	//Checkeo horizontal
	dof = 0;
	float aTan = 1/tan(ra);
	float distH;
	float hx, hy;
	distH = (game->size_x * 15) * (game->size_y * 15);
	hx = game->player.x;
	hy = game->player.y;
	if (ra > M_PI)
	{
		ry = (((int)(game->player.y * 15) / 15 ) * 15 ) - 0.0001;
		rx = ((int)(game->player.y * 15) - ry) * aTan + game->player.x * 15;
		yo = -15;
		xo = -yo * aTan;
		}
	if (ra < M_PI)
	{
		ry = (((int)(game->player.y * 15) / 15 ) * 15 ) + 15;
		rx = ((int)(game->player.y * 15) - ry) * aTan + game->player.x * 15;
		yo = 15;
		xo = -yo * aTan;
	}
	if (ra == 0|| ra == M_PI) //en caso de que el angulo sea perfecto hacia la izquierda o derecha
	{ 
		hx = game->player.x * 15;
		hy = game->player.y * 15;
		dof = game->size_x * game->size_y;
	}
	while (dof < (game->size_x * game->size_y))
	{
		my = ((int)rx) / 15;
		mx = ((int)ry) / 15;
		mlx_pixel_put(game->mlx.mlx, game->mlx.window,ry, rx, PINK); // Para ver los puntos de choque horizontales
		if (inside_matrix(game,my,mx))
		{
			if (horizontal_check(my, mx, angle, game))
			{
				correct_horizontal_hit(&ry,&rx,angle,game);
				dof = game->size_x * game->size_y;
				hx = rx;
				hy = ry;
				distH = distance(game->player.x * 15,game->player.y * 15,hx,hy);
			}
			else
			{
				rx += xo;
			 	ry += yo;
			 	dof++;
			}
		}
		else
			dof = game->size_x * game->size_y;
		
	}
	

	//  //Checkeo vertical 
	dof = 0;
	ra = new_angle( angle + (3*M_PI/2));
	float nTan = 1 * tan(ra);
	float distV;
	float vx, vy;
	distV = (game->size_x * 15) * (game->size_y * 15);;
	vx = game->player.x;
	vy = game->player.y;
	if (ra > M_PI / 2 && ra < (3 * M_PI) / 2)
	{
		rx = (((int)(game->player.x * 15) / 15 ) * 15 ) - 0.0001;
		ry = ((int)(game->player.x * 15) - rx) * nTan + game->player.y * 15;
		xo = -15;
		yo = -xo * nTan;
	}
	if (ra < M_PI/2 || ra > 3*M_PI/2) // ----
	{
		rx = (((int)(game->player.x * 15) / 15 ) * 15 ) + 15;
		ry = ((int)(game->player.x * 15) - rx) * nTan + game->player.y * 15;
		xo = 15;
		yo = -xo * nTan;
	}
	if (ra == M_PI/2 || ra == 3*M_PI/2) //en caso de que el angulo sea perfecto hacia arriba o abajo
	{ 
		vx = game->player.x * 15;
		vy = game->player.y * 15;
		dof = game->size_x * game->size_y;
	}
	while (dof < (game->size_x * game->size_y))
	{
		my = ((int)rx) / 15;
		mx = ((int)ry) / 15;
		if (inside_matrix(game,my,mx))
		{
			mlx_pixel_put(game->mlx.mlx, game->mlx.window,ry, rx, GREEN); // Para ver los puntos de choque verticales
			if (vertical_check(my, mx, angle, game))
			{
				dof = game->size_x * game->size_y;
				correct_vertical_hit(&ry,&rx,angle,game);
				vx = rx;
				vy = ry;
				distV = distance(game->player.x * 15,game->player.y * 15,vx,vy);
			}
			else
			{
				rx += xo;
			 	ry += yo;
			 	dof++;
			}
		}
		else
			dof = game->size_x * game->size_y;
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
	bring_hit_to_closest_wall_point(&ry, &rx , angle ,game);
	// draw_new_line(game, game->player.x * 15,game->player.y * 15,rx,ry,color);
	return (distance(game->player.x * 15,game->player.y * 15,rx,ry) / 15);
}
