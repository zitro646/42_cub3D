/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:45:51 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/09/16 16:15:43 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	pos_is_wall_angled( float angle ,int x, int y, t_game *game)
{
	printf ("Angle checked %f\n",angle);
	if (angle > M_PI && angle > 3 * (M_PI / 2) && game->matrix[y][x - 1].value == '1')
		return (1);
	if (angle < M_PI && angle > (M_PI / 2) && game->matrix[y][x + 1].value == '1')
		return (1);
	// if (angle < M_PI && angle > (M_PI / 2) && game->matrix[y][x - 1].value == '1')
	// 	return (1);
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

void show_ray_data(double angle,double ry,double rx, double yo,double xo )
{
	printf("Angle:%f\n",angle);
	printf ("Checking -> ry:%i,rx:%i\n",(int)ry,(int)rx);
	printf("ry:%f\nrx:%f\nyo:%f\nxo:%f\n",ry,rx,yo,xo);
	return ;
}

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
	return (sqrt((bx - ax)* (bx - ax) + (by - ay)* (by - ay)));
}

void	ray_vision_dda(t_game *game, int color, double angle)
{
	(void)color;
	(void)game;
	int dof;
	int mx,my;
	float rx,ry,xo,yo;
	float ra;
	ra = new_angle( angle - (3*M_PI/2));
	//ra = angle;
	
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
		printf("Looking Up!\n");
		ry = (((int)(game->player.y * 15) / 15 ) * 15 ) - 0.0001;
		rx = ((int)(game->player.y * 15) - ry) * aTan + game->player.x * 15;
		yo = -15;
		xo = -yo * aTan;
		}
	if (ra < M_PI)
	{
		printf("Looking Down!\n");
		ry = (((int)(game->player.y * 15) / 15 ) * 15 ) + 15;
		rx = ((int)(game->player.y * 15) - ry) * aTan + game->player.x * 15;
		yo = 15;
		xo = -yo * aTan;
	}
	if (ra == 0|| ra == M_PI) //en caso de que el angulo sea perfecto hacia la izquierda o derecha
	{ 
		rx = game->player.x * 15;
		ry = game->player.y * 15;
		dof = game->size_x * game->size_y;
	}
	while (dof < (game->size_x * game->size_y))
	{
		my = ((int)rx) / 15;
		mx = ((int)ry) / 15;
		// printf("my:%imx:%i\n",my,mx);
		if (inside_matrix(game,my,mx))
		{
			if (angle > M_PI / 2 && angle < (3 * M_PI) / 2)
			{
				if (pos_is_wall(mx * 15,my * 15, game) || pos_is_wall((mx + 1) * 15,my * 15, game)) // 
				{
					printf("Finds an Horizontal WALL! at!!!\n");
					dof = game->size_x * game->size_y;
					hx = rx;
					hy = ry;
					distH = distance(game->player.x,game->player.y,hx,hy);
				}
				else
				{
					rx += xo;
					ry += yo;
					dof++;
				}
			}
			else if (angle < M_PI/2 || angle > 3*M_PI/2)
			{
				if (pos_is_wall(mx * 15,my * 15, game) || pos_is_wall((mx - 1) * 15,my * 15, game)) // 
				{
					dof = game->size_x * game->size_y;
					hx = rx;
					hy = ry;
					distH = distance(game->player.x,game->player.y,hx,hy);
				}
				else
				{
					// draw_new_line(game, rx , ry, rx + xo, ry + yo, 0xF0FFFF);
					printf("Da una vuelta por que el resultado es %i!!\n",pos_is_wall(mx * 15,my * 15, game));
					printf("- - - - - - - \n");
					// draw_new_line(game, (int)rx, (int)ry, rx + xo, ry + yo ,0xFF000F);
					rx += xo;
					ry += yo;
					dof++;
				}
			}
		}
		else
		{
			// printf("Salio del loop!\n");
			dof = game->size_x * game->size_y;
		}
		
	}
	// draw_new_line(game, game->player.x * 15, game->player.y * 15, rx, ry ,0x00FFFF);
	
	printf ("Termino checkeo Horizontal  \n");
	//  //Checkeo vertical // Sin modificar aun
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
		printf ("Look Left\n");
			
		rx = (((int)(game->player.x * 15) / 15 ) * 15 ) - 0.0001;
		ry = ((int)(game->player.x * 15) - rx) * nTan + game->player.y * 15;
		xo = -15;
		yo = -xo * nTan;
	}
	if (ra < M_PI/2 || ra > 3*M_PI/2) // ----
	{
		printf ("Look Right\n");
		
		rx = (((int)(game->player.x * 15) / 15 ) * 15 ) + 15;
		ry = ((int)(game->player.x * 15) - rx) * nTan + game->player.y * 15;
		xo = 15;
		yo = -xo * nTan;
	}
	if (ra == 0|| ra == M_PI) //en caso de que el angulo sea perfecto hacia arriba o abajo
	{ 
		rx = game->player.x;
		ry = game->player.y;
		dof = 8;
	}
	while (dof < 8)
	{
		my = ((int)rx) / 15;
		mx = ((int)ry) / 15;
		// printf("my:%imx:%i\n",my,mx);
		if (inside_matrix(game,my,mx))
		{
			if (angle > M_PI)
			{
				if (pos_is_wall(mx * 15,my * 15, game) || pos_is_wall(mx * 15,(my + 1) * 15, game)) // 
				{
					dof = game->size_x * game->size_y;
					vx = rx;
					vy = ry;
					distV = distance(game->player.x,game->player.y,vx,vy);
				}
				else
				{
					rx += xo;
					ry += yo;
					dof++;
				}
			}
			else if (angle < M_PI)
			{
				if (pos_is_wall(mx * 15,my * 15, game) || pos_is_wall(mx * 15,(my  - 1)* 15, game)) // 
				{
					dof = game->size_x * game->size_y;
					vx = rx;
					vy = ry;
					distV = distance(game->player.x,game->player.y,vx,vy);
				}
				else
				{
					rx += xo;
					ry += yo;
					dof++;
				}
			}
		}
		else
		{
			printf("Salio del loop!\n");
			dof = game->size_x * game->size_y;
		}
	}
	draw_new_line(game, game->player.x * 15 , game->player.y * 15 , rx  , ry  ,0xFFFFFF);
	draw_new_line(game, game->player.x * 15 + 1 , game->player.y * 15 + 1 , hx  +1  , hy + 1 ,0xFF00FF);
	printf ("distH : %f - distV : %f \n", distH, distV);
	printf("Rayo Rosa es Horizontal -> 0xFF00FF\n");
	printf("Rayo Blanco es Vertical -> 0xFFFFFF\n");

	if (distV < distH)
	{
		printf("Escogemos la distancia V\n");
		rx = vx;
		ry = vy;
	}
	else
	{
		printf("Escogemos la distancia H\n");
		rx = hx;
		ry = hy;
	}
	
	

	printf ("Resultados DDA -_- \n");
}