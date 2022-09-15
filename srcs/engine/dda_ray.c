/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:45:51 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/09/15 13:08:25 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *make_linear_array(t_game *game)
{
	char *aux1;
	//char *aux2;
	int y;
	int x;

	aux1 = "";
	y = 0;
	
	while (game->matrix[y])
	{
		x = 0;
		while (x < game->size_x)
		{
			
			x++;
		}
		y++;
	}
	return (aux1);
	return ("aaaa");
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
	// ra = angle;
	
	//Checkeo horizontal
	
	dof = 0;
	float aTan = 1/tan(ra);
	float distH;
	float hx, hy;
	distH = 100000;
	hx = game->player.x;
	hy = game->player.y;
	// printf("- - - - - - - - - - \n");
	// printf("Pruebas apartes\n");
	// printf("Angle:%f\naTan:%f\n",4.683187,-1/(tan(4.683187)));
	// printf("- - - - - - - - - - \n");
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
		rx = ((game->player.y * 15) - ry) * aTan + game->player.x * 15;
		yo = 15;
		xo = -yo * aTan;
		// printf("ry:%f\nrx:%f\nyo:%f\nxo:%f\n",ry,rx,yo,xo);
	}
	if (ra == 0|| ra == M_PI) //en caso de que el angulo sea perfecto hacia la izquierda o derecha
	{ 
		rx = game->player.x * 15;
		ry = game->player.y * 15;
		dof = game->size_x * game->size_y;
	}
	// printf("Angle:%f\naTan:%f\n",ra,aTan);
	// printf("Test\nry:%f\nrx:%f\nyo:%f\nxo:%f\n",ry,rx,yo,xo);
	//draw_new_line(game, (int)(game->player.x * 15), (int)(game->player.y * 15), (int)rx , (int)ry ,0xFFFFFF);
	// printf ("En pixeles : RX:%f - RY:%f - \n", rx , ry);
	// printf ("En flotante : RX:%f - RY:%f \n", rx/15 , ry / 15);
	// printf ("En Matrix : RX:%i - RY:%i \n", (int)rx/15 , (int)ry / 15);
	// printf ("checkeo Horizontal - Condiciones \n");
	while (dof < (game->size_x * game->size_y))
	{
		my = ((int)rx) / 15;
		mx = ((int)ry) / 15;
		// printf("my:%imx:%i\n",my,mx);
		if (inside_matrix(game,my,mx))
		{
			// printf("Inside matrix my:%imx:%i\n",my,mx);
			if (pos_is_wall(mx * 15,my * 15, game)) // 
			{
				printf("Finds an Horizontal WALL! at!!!\n");
				printf("ry:%frx:%f\n",ry,rx);
				// printf("my:%imx:%i\n",my,mx);
				// printf("xo:%fyo:%f\n",xo,yo);
				dof = game->size_x * game->size_y;
				hx = rx;
				hy = ry;
				distH = distance(game->player.x,game->player.y,hx,hy);
				// draw_new_line(game, game->player.x * 15, game->player.y * 15, hx  , hy ,0xFFFFFF);
			}
			else
			{
				// draw_new_line(game, game->player.x * 15, game->player.y * 15, rx, ry,0xFF000F);
				rx += xo;
				ry += yo;
				dof++;
			}
		}
		else
		{
			// printf("Salio del loop!\n");
			dof = game->size_x * game->size_y;
		}
		
	}
	//draw_new_line(game, (int)(game->player.x * 15), (int)(game->player.y * 15), (int)rx , (int)ry ,0xF0F0F0);
	
	// if (inside_matrix(game, ry,rx))
	// 	draw_new_line(game, game->player.x * 15, game->player.y * 15, rx * 15, ry * 15,color);
	//draw_new_line(game, game->player.x * 15, game->player.y * 15, game->player.x * 15 + sin(ra) * 5, game->player.y * 15 + cos(ra) * 5,0xFFFF00); // Muestra la direccion del angulo
	
	printf ("Termino checkeo Horizontal  \n");
	//  //Checkeo vertical // Sin modificar aun
	dof = 0;
	// ra = 1.983189;
	ra = new_angle( angle + (3*M_PI/2));
	float nTan = 1 * tan(ra);
	float distV;
	float vx, vy;
	distV = 100000;
	vx = game->player.x;
	vy = game->player.y;
	// printf("- - - - - - - - - - \n");
	// printf("Pruebas apartes\n");
	// printf("Angle:%f\naTan:%f\n",3.083188,-1 * tan(3.083188));
	// printf("- - - - - - - - - - \n");
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
	// printf("Player pos :[%f][%f] -- [%f][%f]\n",game->player.x,game->player.y,game->player.x * 15,game->player.y * 15);
	// printf("Angle:%f\naTan:%f\n",ra,nTan);
	// printf("Test\nry:%f\nrx:%f\nyo:%f\nxo:%f\n",ry,rx,yo,xo);
	while (dof < 8)
	{
		my = ((int)rx) / 15;
		mx = ((int)ry) / 15;
		// printf("my:%imx:%i\n",my,mx);
		if (inside_matrix(game,my,mx))
		{
			// printf("Inside matrix my:%imx:%i\n",my,mx);
			if (pos_is_wall(mx * 15,my * 15, game)) // 
			{
				printf("Finds a WALL! at!!!\n");
				printf("ry:%frx:%f\n",ry,rx);
				printf("my:%imx:%i\n",my,mx);
				printf("xo:%fyo:%f\n",xo,yo);
				dof = game->size_x * game->size_y;
				vx = rx;
				vy = ry;
				distV = distance(game->player.x,game->player.y,vx,vy);
				// draw_new_line(game, game->player.x * 15, game->player.y * 15, hx  , hy ,0xFFFFFF);
			}
			else
			{
				// draw_new_line(game, game->player.x * 15, game->player.y * 15, rx, ry,0xFF000F);
				rx += xo;
				ry += yo;
				dof++;
			}
		}
		else
		{
			printf("Salio del loop!\n");
			dof = game->size_x * game->size_y;
		}
	}
	// // printf ("Termino checkeo Vertical  \n");

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
	
	draw_new_line(game, game->player.x * 15, game->player.y * 15, rx, ry ,0x00FFFF);

	printf ("Resultados DDA -_- \n");
	//printf ("Horizontal :[%f] - [%f] -> distancia de golpe : %f\n", hy, hx, distH);
	// printf ("Vertical :[%f] - [%f] -> distancia de golpe : %f\n", vy, vx, distV);
	// draw_new_line(game, game->player.x * 15, game->player.y * 15, vx * 15, vy * 15,0xFF00FF);
	//draw_new_line(game, game->player.x * 15, game->player.y * 15, hx * 15, hy * 15,0xFFFF00);
	// draw_new_line(game,game->player.x * 15,game->player.y * 15 ,rx * 15 ,ry * 15,0x00FF00);
	// draw_new_line(game,0,0,150,150,color);
	// draw_new_line(game,150,150,200,115,color);

}

