/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:45:51 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/09/12 14:45:09 by mortiz-d         ###   ########.fr       */
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
	// printf(" y -> %i   (%i - %i)\n", y,  game->matrix_height * 15 , 0);
	// printf(" x -> %i   (%i - %i)\n", x,  game->matrix_width * 15 , 0);
	if (y > game->matrix_height * 15 || y < 0)
	{
		// printf("Salta y\n");
		return (0);
	}
	else if (x > game->matrix_width * 15 || x < 0)
	{
		// printf("Salta x\n");
		return (0);
	}
	// printf("punto dentro de matrix\n");
	return (1);
}

void	destination_point(t_game *game, int *hit_x, int *hit_y)
{
	double	line;
	double	test_x;
	double	test_y;

	if (game->matrix_height > game->matrix_width)
		line = game->matrix_height * 15;
	else
		line = game->matrix_width * 15;
	// printf("player pos : [%f][%f]  distance added --> %f\n", game->player.y * 15 + 7, game->player.x * 15 + 7, line);
	*hit_y = (game->player.y * 15) + (cos(game->player.angle) * line);
	*hit_x = (game->player.x * 15) + (sin(game->player.angle) * line);
	test_x = (*hit_x);
	test_y = (*hit_y);
	// printf("Resultados del punto de destino [%f][%f]\n", test_y, test_x );
	return ;
}

void	ray_vision_inside_matrix(t_game *game, int color, double angle)
{
	double	line;
	int		i;
	int		j;
	int		test_x;
	int		test_y;

	line = 0;
	j = (game->player.y * 15) + (cos(game->player.angle) * line);
	i = (game->player.x * 15) + (sin(game->player.angle) * line);
	test_x = 0;
	test_y = 0;
	//destination_point(game, &test_x, &test_y);
	while (inside_matrix(game, i, j))
	{
		j = (game->player.y * 15) + (cos(game->player.angle + angle) * line);
		i = (game->player.x * 15) + (sin(game->player.angle + angle) * line);
		mlx_pixel_put(game->mlx.mlx, game->mlx.window,
			j, i, color);
		line += 0.3;
		//printf("Puntos de contacto : [%i][%i]\n",j,i);
	}
}

float distance(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax)* (bx - ax) + (by - ay)* (by - ay)));
}

void	ray_vision_dda(t_game *game, int color, double angle)
{
	(void)color;
	(void)angle;
	(void)game;
	int mx,my,dof,mp;
	float rx,ry,ra,xo,yo;
	ra = game->player.angle;

	
	//Checkeo horizontal
	dof = 0;
	float aTan = -1/tan(ra);
	float distH;
	float hx, hy;
	distH = 100000;
	hx = game->player.x;
	hy = game->player.y;
	if (ra > M_PI)
	{
		ry = (((int)game->player.y / 15)*15);
		rx = (game->player.y - ry) * aTan + game->player.x;
		yo = -15;
		xo = -yo * aTan;
		//printf("ry:%f\nrx:%f\nyo:%f\nxo:%f\n",ry,rx,yo,xo);
	}
	if (ra < M_PI)
	{
		ry = (((int)game->player.y / 15)*15) + 15;
		rx = (game->player.y - ry) * aTan + game->player.x;
		yo = 15;
		xo = -yo * aTan;
	}
	if (ra == 0|| ra == M_PI) //en caso de que el angulo sea perfecto hacia la izquierda o derecha
	{ 
		rx = game->player.x;
		ry = game->player.y ;
		dof = 8;
	}
	printf ("checkeo Horizontal - Condiciones \n");
	// printf ("%i - %i \n", (int)rx/15 , (int)ry / 15);
	while (dof < 8)
	{
		mx = (int) rx / 15;
		my = (int) ry / 15;
		mp=my*game->matrix_width+mx;
		printf ("%d - %d - %d\n", mx , my , mp);
		if (mp > 0 && mp < game->matrix_width * game->matrix_height && game->matrix[my][mx].value == '1') // 
		{
			dof = 8;
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
	// printf ("Termino checkeo Horizontal  \n");
	 //Checkeo vertical // Sin modificar aun
	dof = 0;
	float nTan = -tan(ra);
	float distV;
	float vx, vy;
	distV = 100000;
	vx = game->player.x;
	vy = game->player.y;
	if (ra > M_PI / 2 && ra < (3 * M_PI) / 2)
	{
		rx = (((int)game->player.x / 15)*15) - 0.0001;
		ry = (game->player.x - rx) * nTan + game->player.y;
		xo = -15;
		yo = -xo * nTan;
	}
	if (ra < M_PI/2 || ra > 3*M_PI/2) // ----
	{
		rx = (((int)game->player.x / 15)*15) + 15;
		ry = (game->player.x - rx) * nTan + game->player.y;
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
		mx = (int) rx / 15;
		my = (int) ry / 15;
		mp=my*game->matrix_width+mx;
		if (mp > 0 && mp < game->matrix_width * game->matrix_height && game->matrix[my][mx].value == '1') // && game->matrix[my][mx].value == '1'
		{
			dof = 8;
			vx = rx;
			vy = ry;
			distV = distance(game->player.x,game->player.y,hx,hy);
		}
		else
		{
			rx += xo;
			ry += yo;
			dof++;
		}
	}
	// printf ("Termino checkeo Vertical  \n");

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
	
	printf ("Resultados DDA -_- \n");
	//printf ("Horizontal :[%f] - [%f] -> distancia de golpe : %f\n", hy, hx, distH);
	// printf ("Vertical :[%f] - [%f] -> distancia de golpe : %f\n", vy, vx, distV);
	draw_new_line(game, game->player.x * 15, game->player.y * 15, vx * 15, vy * 15,0xFF00FF);
	draw_new_line(game, game->player.x * 15, game->player.y * 15, hx * 15, hy * 15,0xFFFF00);
	// draw_new_line(game,game->player.x * 15,game->player.y * 15 ,rx * 15 ,ry * 15,0x00FF00);
	// draw_new_line(game,0,0,150,150,color);
	// draw_new_line(game,150,150,200,115,color);

}




// void	ray_vision_dda(t_game *game, int color, double angle)
// {
// 	(void)color;
// 	(void)angle;
// 	int		aux_y;
// 	int		aux_x;
// 	double	x;
// 	double	y;
// 	double	length;
// 	double	x2;
// 	double	y2;
// 	double	dx;
// 	double	dy;
// 	double	aux_dx;
// 	double	aux_dy;

// 	//ray_vision_inside_matrix(game,color,angle);
// 	destination_point(game, &aux_x, &aux_y);
// 	x2 = aux_x / 15;
// 	y2 = aux_y / 15;
// 	aux_dx = fabs(x2 - game->player.x);
// 	aux_dy = fabs(y2 - game->player.y);
// 	if (aux_dx <= aux_dy)
// 		length = aux_dy;
// 	else
// 		length = aux_dx;
// 	dx = (x2 - game->player.x)/length;
// 	dy = (y2 - game->player.y)/length;
// 	x = game->player.x + 0.5;
// 	y = game->player.y + 0.5;
// 	mlx_pixel_put(game->mlx.mlx, game->mlx.window,
// 			y * 15, x * 15, 0x00FF00);
// 	while (inside_matrix(game, y, x))
// 	{
// 		x += dx;
// 		y += dy;
// 		mlx_pixel_put(game->mlx.mlx, game->mlx.window,
// 			y * 15, x * 15, 0x00FF00);
// 	}
// }