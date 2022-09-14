/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:39:19 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/14 17:32:07 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		game->ray[i].ray = i;
		i++;
	}
}

void	ray_angle(t_game *game)
{
	int	r;
	int	i;

	r = game->width / 2;
	i = 0;
	game->ray[game->width / 2].ray_angle = game->player.angle;
	while (r < game->width)
	{
		game->ray[r].ray_angle = game->ray[game->width / 2].ray_angle
			+ game->diff_angle * i;
		if (game->ray[r].ray_angle > 2 * M_PI || game->ray[r].ray_angle < 0)
			game->ray[r].ray_angle = new_angle(game->ray[r].ray_angle);  
		r++;
		i++;
	}
	r = (game->width / 2) - 1;
	i = 0;
	while (r >= 0)
	{
		game->ray[r].ray_angle = game->ray[game->width / 2].ray_angle
				- game->diff_angle * i;
		if (game->ray[r].ray_angle > 2 * M_PI || game->ray[r].ray_angle < 0)
			game->ray[r].ray_angle = new_angle(game->ray[r].ray_angle); 
		r--;
		i++;
	}
}

int is_wall( int x_pixel, int y_pixel, t_game *game)
{
	int x;
	int y;

	x = x_pixel;
	y = y_pixel;
	if (game->matrix[x][y].value == '1')
		return (1);
	return (0);
}

void	ray_hit_h(t_game *game)
{	
	int		r;
	double	new_hit_yh;
	double	new_hit_xh;
	double	y_step;
	double	x_step;

	r = 0;
	while (r < game->width)
	{
		new_hit_yh = game->player.y - 0.5;
		if (game->ray[r].ray_at == 2 || game->ray[r].ray_at == 3)
			new_hit_yh++;
		if (game->ray[r].ray_at == 1 || game->ray[r].ray_at == 4)
			new_hit_xh = game->player.x - (0.5 / tan(game->ray[r].ray_angle));
		else
			new_hit_xh = game->player.x + (0.5 / tan(game->ray[r].ray_angle));
		y_step = 1;
		x_step = y_step / tan(game->ray[r].ray_angle);

		if (game->ray[r].ray_angle == 0 || game->ray[r].ray_angle == 2 * M_PI
				|| game->ray[r].ray_angle == M_PI)
		{
			x_step = 1;
			y_step = 0;
		}
		else if (game->ray[r].ray_angle == M_PI / 2 || game->ray[r].ray_angle == (3/2) * M_PI)
		{
			x_step = 0;
			y_step = 1;
		}
		if (new_hit_xh < 0  || new_hit_xh > game->size_x)
		{
			new_hit_xh = game->player.x;
			x_step = 1;
			y_step = 0;
			game->ray[r].hor = 1;
		}
		/*
		if (r == 512 || r == 0 || r == 1023 || r == 510 || r == 514)
		{
			printf("hit[%d](%f, %f)\n", r, new_hit_xh, new_hit_yh);
			printf("step[%d](%f, %f)\n", r, x_step, y_step);
		}
		*/
		while (!is_wall(new_hit_xh, new_hit_yh, game) && game->ray[r].hor != 1)
		{
		//	printf("hit[%d](%f, %f)\n", r, new_hit_xh, new_hit_yh);
			if (game->ray[r].ray_at == 4 || game->ray[r].ray_at == 3)
			{
				new_hit_yh -= y_step;
				new_hit_xh -= x_step;
			}
			else if (game->ray[r].ray_at == 1 || game->ray[r].ray_at == 2)
			{
				new_hit_yh += y_step;
				new_hit_xh += x_step;
			}
			if (new_hit_xh < 0  || new_hit_xh > game->size_x)
			{
				game->ray[r].hor = 1;
				break;
			}
			is_wall(new_hit_xh, new_hit_yh, game);
		}
		game->ray[r].hit_xh = new_hit_xh;
		game->ray[r].hit_yh = new_hit_yh;
		/*
		if (r == 512 || r == 0 || r == 1023 || r == 510 || r == 514)
		{
			printf("hit[%d](%f, %f)\n", r, new_hit_xh, new_hit_yh);
			printf("step[%d](%f, %f)\n", r, x_step, y_step);
		}
		*/
		r++;
	}
}

void	ray_hit_v(t_game *game)
{	
	int		r;
	double	new_hit_yv;
	double	new_hit_xv;
	double	y_step;
	double	x_step;

	r = 0;
	while (r < game->width)
	{
		new_hit_xv = game->player.x - 0.5;
		if (game->ray[r].ray_at == 1 || game->ray[r].ray_at == 2)
			new_hit_xv++;
		if (game->ray[r].ray_at == 1 || game->ray[r].ray_at == 4)
			new_hit_yv = game->player.y - (0.5 * tan(game->ray[r].ray_angle));
		else
			new_hit_yv = game->player.y + (0.5 * tan(game->ray[r].ray_angle));
		x_step = 1;
		y_step = tan(game->ray[r].ray_angle);
		if (game->ray[r].ray_angle == 0 || game->ray[r].ray_angle == 2 * M_PI
				|| game->ray[r].ray_angle == M_PI)
		{
			x_step = 1;
			y_step = 0;
		}
		else if (game->ray[r].ray_angle == M_PI / 2 || game->ray[r].ray_angle == (3/2) * M_PI)
		{
			x_step = 0;
			y_step = 1;
		}
		if (new_hit_yv < 0  || new_hit_yv > game->size_y)
		{
			new_hit_yv = game->player.y;
			x_step = 1;
			y_step = 0;
			game->ray[r].ver = 1;
		}

		if (r == 512 || r == 0 || r == 1023 || r == 510 || r == 514)
		{
			printf("hit[%d](%f, %f)\n", r, new_hit_xv, new_hit_yv);
			printf("step[%d](%f, %f)\n", r, x_step, y_step);
		}

		while (!is_wall(new_hit_xv, new_hit_yv, game) && game->ray[r].ver != 1)
		{
		//	printf("hit[%d](%f, %f)\n", r, new_hit_xh, new_hit_yh);
			if (game->ray[r].ray_at == 4 || game->ray[r].ray_at == 3)
			{
				new_hit_yv -= y_step;
				new_hit_xv -= x_step;
			}
			else if (game->ray[r].ray_at == 1 || game->ray[r].ray_at == 2)
			{
				new_hit_yv += y_step;
				new_hit_xv += x_step;
			}
			if (new_hit_xv < 0  || new_hit_xv > game->size_x)
			{
				game->ray[r].ver = 1;
				break;
			}
			is_wall(new_hit_xv, new_hit_yv, game);
		}
		/*
		if (r == 512 || r == 0 || r == 1023 || r == 510 || r == 514)
		{
			printf("hit[%d](%f, %f)\n", r, new_hit_xv, new_hit_yv);
			printf("step[%d](%f, %f)\n", r, x_step, y_step);
		}
		*/
		game->ray[r].hit_xv = new_hit_xv;
		game->ray[r].hit_yv = new_hit_yv;
		r++;
	}
}
/*
void	ray_hit(t_game *game)
{
	int		r;
	double	pow_xh;
	double	pow_yh;
	double	pow_yv;
	double	pow_xv;
	double	abs;
	double	distance_h;
	double	distance_v;

	r = 0;
	while (r < game->width)
	{
		if (game->ray[r].hor == 0)
		{
			pow_xh = pow(game->ray[r].hit_xh - game->player.x, 2);
			pow_yh = pow(game->ray[r].hit_yh - game->player.y, 2);
			abs = pow_xh + pow_yh;
			if (abs < 0)
				abs *= - 1;
			distance_h = sqrt(abs);
		}
		else
			distance_h = 0;
		if (game->ray[r].ver == 0)
		{
			pow_xv = pow(game->ray[r].hit_xv - game->player.x, 2);
			pow_yv = pow(game->ray[r].hit_yv - game->player.y, 2);
			abs = pow_xv + pow_yv;
			if (abs < 0)
				abs *= - 1;
			distance_v = sqrt(abs);
		}
		else
			distance_v = 0;
		if (distance_v < distance_h && distance_v > 0)
			game->ray[r].distance = distance_v;
		else if (distance_h <= distance_v && distance_h > 0)
			game->ray[r].distance = distance_h;

		r++;
	}
}
*/


void	ray_hit(t_game *game)
{
	int		r;
	double	new_hit_x;
	double	new_hit_y;
	double	cont;

	r = 0;
	while (r < game->width)
	{
		cont = 0.25;
		new_hit_x = (game->player.y * 15) + (cos(game->ray[r].ray_angle) * cont); 
		//new_hit_x = (game->player.y) + (cos(game->ray[r].ray_angle) * cont); 
		//new_hit_y = (game->player.x) + (sin(game->ray[r].ray_angle) * cont);
		new_hit_y = (game->player.x * 15) + (sin(game->ray[r].ray_angle) * cont);
		while (!pos_is_wall(new_hit_x, new_hit_y, game))
		{
			new_hit_x = (game->player.y * 15) + (cos(game->ray[r].ray_angle) * cont); 
			//new_hit_x = (game->player.y) + (cos(game->ray[r].ray_angle) * cont); 
			new_hit_y = (game->player.x * 15) + (sin(game->ray[r].ray_angle) * cont);
			//new_hit_y = (game->player.x) + (sin(game->ray[r].ray_angle) * cont);
			//pos_is_wall(new_hit_x, new_hit_y, game);
			//is_wall(new_hit_y, new_hit_x, game);
			cont += 0.25;
		}
	//	game->ray[r].hit_y = new_hit_x;
		game->ray[r].hit_y = new_hit_x / 15;
	//	game->ray[r].hit_x = new_hit_y;
		game->ray[r].hit_x = new_hit_y / 15;
		r++;
	}
}


void	ray_distance(t_game *game)
{
	int		r;
	double	pow_x;
	double	pow_y;
	double	abs;

	r = 0;
	while (r < game->width)
	{
		pow_x = pow(game->ray[r].hit_x - game->player.x, 2);
		pow_y = pow(game->ray[r].hit_y - game->player.y, 2);
		abs = pow_x + pow_y;
		if (abs < 0)
			abs *= - 1;
		game->ray[r].distance = sqrt(abs);
		r++;
	}
}



void    ray(t_game *game)
{
	int 	r;
	double	angle;
	double	aux;
	double	proportion;

	ray_angle(game);
	ray_at(game);
//	ray_hit_h(game);
//	ray_hit_v(game);
	ray_hit(game);
	ray_distance(game);

	r = 0;
	while (r < game->width)
	{
		angle = - M_PI / 4 + (game->diff_angle * r);
		game->ray[r].point = cos(angle) * game->ray[r].distance;
		r++;
	}
	//ray_at(game);
	aux = 500;
	proportion = tan(M_PI / 4) * (game->width / 2);
	r = 0;
	while (r < game->width)
	{
		game->ray[r].wall = aux /(aux / proportion * game->ray[r].point);
		r++;
	}

/*
	printf("ray[0]: %f, hit[0]: (%f, %f)\n", game->ray[0].ray_angle,
			game->ray[0].hit_x, game->ray[0].hit_y);
	printf("looking at: %d\n", game->ray[0].ray_at);
	printf("distance to hit: %f\n", game->ray[0].distance);
	printf("point: %f\n", game->ray[0].point);
	printf("wall size: %f\n", game->ray[0].wall);
*/
/*
	if (game->player.advance == 0 && game->player.turn == 0)
	{
		printf("ray[512]: %f, hit[512]: (%f, %f)\n", game->ray[512].ray_angle,
			game->ray[512].hit_x, game->ray[512].hit_y);
		printf("looking at: %d\n", game->ray[512].ray_at);
	}
*/
//	printf("distance to hit: %f\n", game->ray[512].distance);
//	printf("point: %f\n", game->ray[512].point);
//	printf("wall size: %f\n", game->ray[512].wall);
/*
	printf("ray[1023]: %f, hit[1023]: (%f, %f)\n", game->ray[1023].ray_angle,
			game->ray[1023].hit_x, game->ray[1023].hit_y);
	printf("looking at: %d\n", game->ray[1023].ray_at);
	printf("distance to hit: %f\n", game->ray[1023].distance);
	printf("point: %f\n", game->ray[1023].point);
	printf("wall size: %f\n", game->ray[1023].wall);
*/
}
