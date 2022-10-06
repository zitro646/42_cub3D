/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:47:50 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/06 03:09:55 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//3.926991
//3.926991

//

int is_angle_testing(float angle, float angle_2)
{
	int new_angle;
	int testing;

	new_angle = angle * 1000000;
	testing = angle_2 * 1000000;
	if (new_angle == testing)
		return (1);
	return (0);
}

int	hit_check_testing(int my, int mx, float  angle, t_game *game)
{
	int new_angle;
	int testing;

	new_angle = angle * 1000000;
	testing = 5 * (M_PI * 2) / 8 * 1000000;
	if (new_angle  == testing)
	{	
		if (new_pos_is_wall(my + 1,mx, game))
			return (1);
		if (new_pos_is_wall(my ,mx + 1, game))
			return (1);
	}
	testing = (M_PI * 2) / 8 * 1000000;
	if (new_angle == testing)
	{	
		if (new_pos_is_wall(my - 1,mx, game))
			return (1);
		if (new_pos_is_wall(my ,mx - 1, game))
			return (1);
	}
	if (new_pos_is_wall(my,mx, game) )
	{
		return  (1);
	}
	return (0);
}



//COPIA DE PRUEBAS

double	ray_vision_dda_testing(t_game *game, double angle, int r)
{
	(void)(r);
	int dof;
	int mx,my;
	float rx,ry,xo,yo;

	printf("________________\n");
	printf("Angle -> %f\n",angle);
	//Checkeo horizontal
	dof = 0;
	float aTan = -1/tan(angle);
	float distH;
	float hx, hy;
	distH = (game->size_c * M_SIZE) * (game->size_f * M_SIZE);
	hx = game->player.c;
	hy = game->player.f;
	if (angle == 0 || angle == M_PI || angle == 2 * M_PI)
	{
		hx = game->player.c * M_SIZE;
		hy = game->player.f * M_SIZE;
		dof = (game->size_c * M_SIZE) * (game->size_f * M_SIZE);
	}
	else if (angle > M_PI)
	{
		
		ry = (((int)(game->player.f * M_SIZE) / M_SIZE ) * M_SIZE ) - 0.0001;
		if ( is_angle_testing (5 * (M_PI * 2) / 8,angle))
			rx = ((int)(game->player.f * M_SIZE) - ry) * aTan + game->player.c * M_SIZE + 0.0001;
		else
			rx = ((int)(game->player.f * M_SIZE) - ry) * aTan + game->player.c * M_SIZE;
		yo = -M_SIZE;
		xo = -yo * aTan;
	}
	else if (angle < M_PI)
	{
		ry = (((int)(game->player.f * M_SIZE) / M_SIZE ) * M_SIZE ) + M_SIZE;
		if ( is_angle_testing ((M_PI * 2) / 8,angle))
			rx = ((int)(game->player.f * M_SIZE) - ry) * aTan + game->player.c * M_SIZE - 0.0001;
		else
			rx = ((int)(game->player.f * M_SIZE) - ry) * aTan + game->player.c * M_SIZE;
		
		yo = M_SIZE;
		xo = -yo * aTan;
	}
	if (dof != (game->size_c * M_SIZE) * (game->size_f * M_SIZE))
		printf("Eje Horizontal 1º -> %f %f\n",ry/M_SIZE, rx/M_SIZE);
	//new_pos_is_wall(my,mx,game)
	//horizontal_check(my,mx,angle,game)
	while (dof < (game->size_c * game->size_f))
	{
		my = (ry) / M_SIZE;
		mx = (rx) / M_SIZE;
		mlx_pixel_put(game->mlx.mlx, game->mlx.window,rx, ry, WHITE);
		if (inside_matrix(game,my,mx))
		{
			if (new_pos_is_wall(my,mx,game))
			{
				dof = game->size_c * game->size_f;
				hx = rx;
				hy = ry;
				distH = distance(game->player.c * M_SIZE,game->player.f * M_SIZE,hx,hy);
				// draw_new_line(game, game->player.f * M_SIZE,game->player.c * M_SIZE,ry,rx,WHITE);
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
			dof = (game->size_c * M_SIZE) * (game->size_f * M_SIZE);
		}

	}
		
	//__________________________________

	//Checkeo vertical
	dof = 0;
	float nTan = -tan(angle);
	float distV;
	float vx, vy;

	distV = (game->size_c * M_SIZE) * (game->size_f * M_SIZE);
	vx = game->player.c;
	vy = game->player.f;
	if (angle == M_PI/2 || angle == 3*M_PI/2)
	{
		vx = game->player.c * M_SIZE;
		vy = game->player.f * M_SIZE;
		dof = game->size_c * game->size_f;
	}
	else if (angle > M_PI / 2 && angle < (3 * M_PI) / 2)
	{
		rx = (((int)(game->player.c * M_SIZE) / M_SIZE ) * M_SIZE ) - 0.0001;
		ry = ((int)(game->player.c * M_SIZE) - rx) * nTan + game->player.f * M_SIZE;
		xo = -M_SIZE;
		yo = -xo * nTan;
	}
	else if (angle < M_PI/2 || angle > 3*M_PI/2)
	{
		rx = (((int)(game->player.c * M_SIZE) / M_SIZE ) * M_SIZE ) + M_SIZE;
		ry = ((int)(game->player.c * M_SIZE) - rx) * nTan + game->player.f * M_SIZE;
		xo = M_SIZE;
		yo = -xo * nTan;
	}
	if (dof != (game->size_c * M_SIZE) * (game->size_f * M_SIZE))
		printf("Eje Vertical 1º -> %f %f\n",ry/M_SIZE, rx/M_SIZE);
	//new_pos_is_wall(my,mx,game)
	//vertical_check(my, mx, angle, game)
	while (dof < (game->size_c * game->size_f))
	{
		my = (ry) / M_SIZE;
		mx = (rx) / M_SIZE;
		mlx_pixel_put(game->mlx.mlx, game->mlx.window,rx, ry, GREEN);
		if (inside_matrix(game,my,mx))
		{
			if (new_pos_is_wall(my,mx,game))
			{
				dof = game->size_c * game->size_f;
				vx = rx;
				vy = ry;
				distV = distance(game->player.c * M_SIZE,game->player.f * M_SIZE,vx,vy);
				// draw_new_line(game, game->player.f * M_SIZE,game->player.c * M_SIZE,ry,rx,RED);
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
			dof = (game->size_c * M_SIZE) * (game->size_f * M_SIZE);
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
	
	draw_new_line(game, game->player.f * M_SIZE,game->player.c * M_SIZE,ry,rx,r);
	return (distance(game->player.c * M_SIZE, game->player.f * M_SIZE, rx, ry) / M_SIZE);
}














































































































//COPIA VALIDA -pls no joder :(
/*
double	ray_vision_dda_testing(t_game *game, double angle, int r)
{
	(void)(r);
	int dof;
	int mx,my;
	float rx,ry,xo,yo;

	//Checkeo horizontal
	dof = 0;
	float aTan = -1/tan(angle);
	float distH;
	float hx, hy;
	distH = (game->size_c * M_SIZE) * (game->size_f * M_SIZE);
	hx = game->player.c;
	hy = game->player.f;
	if (angle == 0 || angle == M_PI || angle == 2 * M_PI)
	{
		hx = game->player.c * M_SIZE;
		hy = game->player.f * M_SIZE;
		dof = (game->size_c * M_SIZE) * (game->size_f * M_SIZE);
	}
	else if (angle > M_PI)
	{
		ry = (((int)(game->player.f * M_SIZE) / M_SIZE ) * M_SIZE ) - 0.0001;
		rx = ((int)(game->player.f * M_SIZE) - ry) * aTan + game->player.c * M_SIZE;
		yo = -M_SIZE;
		xo = -yo * aTan;
	}
	else if (angle < M_PI)
	{
		ry = (((int)(game->player.f * M_SIZE) / M_SIZE ) * M_SIZE ) + M_SIZE;
		rx = ((int)(game->player.f * M_SIZE) - ry) * aTan + game->player.c * M_SIZE;
		yo = M_SIZE;
		xo = -yo * aTan;
	}

	while (dof < (game->size_c * game->size_f))
	{
		my = (ry) / M_SIZE;
		mx = (rx) / M_SIZE;
		mlx_pixel_put(game->mlx.mlx, game->mlx.window,rx, ry, WHITE);
		if (inside_matrix(game,my,mx))
		{
			if (new_pos_is_wall(my, mx, game))
			{
				dof = game->size_c * game->size_f;
				hx = rx;
				hy = ry;
				distH = distance(game->player.c * M_SIZE,game->player.f * M_SIZE,hx,hy);
				// draw_new_line(game, game->player.f * M_SIZE,game->player.c * M_SIZE,ry,rx,WHITE);
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
			dof = (game->size_c * M_SIZE) * (game->size_f * M_SIZE);
		}

	}
		
	//__________________________________

	
	//Checkeo vertical
	dof = 0;
	float nTan = -tan(angle);
	float distV;
	float vx, vy;

	distV = (game->size_c * M_SIZE) * (game->size_f * M_SIZE);
	vx = game->player.c;
	vy = game->player.f;
	if (angle == M_PI/2 || angle == 3*M_PI/2)
	{
		vx = game->player.c * M_SIZE;
		vy = game->player.f * M_SIZE;
		dof = game->size_c * game->size_f;
	}
	else if (angle > M_PI / 2 && angle < (3 * M_PI) / 2)
	{
		rx = (((int)(game->player.c * M_SIZE) / M_SIZE ) * M_SIZE ) - 0.0001;
		ry = ((int)(game->player.c * M_SIZE) - rx) * nTan + game->player.f * M_SIZE;
		xo = -M_SIZE;
		yo = -xo * nTan;
	}
	else if (angle < M_PI/2 || angle > 3*M_PI/2)
	{
		rx = (((int)(game->player.c * M_SIZE) / M_SIZE ) * M_SIZE ) + M_SIZE;
		ry = ((int)(game->player.c * M_SIZE) - rx) * nTan + game->player.f * M_SIZE;
		xo = M_SIZE;
		yo = -xo * nTan;
	}

	while (dof < (game->size_c * game->size_f))
	{
		my = (ry) / M_SIZE;
		mx = (rx) / M_SIZE;
		mlx_pixel_put(game->mlx.mlx, game->mlx.window,rx, ry, GREEN); // Para ver los puntos de choque horizontales
		if (inside_matrix(game,my,mx))
		{
			if (new_pos_is_wall(my, mx, game))
			{
				dof = game->size_c * game->size_f;
				vx = rx;
				vy = ry;
				distV = distance(game->player.c * M_SIZE,game->player.f * M_SIZE,vx,vy);
				// draw_new_line(game, game->player.f * M_SIZE,game->player.c * M_SIZE,ry,rx,RED);
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
			dof = (game->size_c * M_SIZE) * (game->size_f * M_SIZE);
		}

	}
	
	if (distV < distH)
	{
		rx = vx;
		ry = vy;
		// game->ray[r].hit_vertical = 1;
		// game->ray[r].hit_horizontal = 0;
	}
	else
	{
		rx = hx;
		ry = hy;
		// game->ray[r].hit_horizontal = 1;
		// game->ray[r].hit_vertical = 0;
	}
	
	// game->ray[r].hit_f = rx / 30;
	// game->ray[r].hit_c = ry / 30;
	
	// draw_new_line(game, game->player.f * M_SIZE,game->player.c * M_SIZE,ry,rx,RED);
	return (distance(game->player.c * 30, game->player.f * 30, rx, ry) / 30);
}
*/