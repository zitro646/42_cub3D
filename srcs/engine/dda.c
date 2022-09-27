/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:47:50 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/27 16:27:39 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


double	dda(t_game *game, int r)
{
	double	pos_fh;
	double	pos_ch;

	double	pos_fv;
	double	pos_cv;

	double	tangle;
	double	aux;
	int		valid;

	tangle = tan(game->ray[r].ray_angle);
	printf("angle->%f\n", game->ray[r].ray_angle);
	printf("tangle->%f\n", tangle);
	valid = 0;

	pos_fh = game->player.f - 0.5;
	if (tangle < 0.0001 && tangle > -0.0001)
		pos_fh += 0.5;
	else if (game->ray[r].ray_angle < M_PI)
		pos_fh++;
	if (tangle > game->size_f && tangle > game->size_c)
		tangle = 0;
	pos_ch = game->player.c - (0.5 * tangle);
	if (tangle > game->size_f && tangle > game->size_c)

	if (game->ray[r].ray_at == 3 || game->ray[r].ray_at == 4) 
	{
		aux = round(pos_ch) - pos_ch;
		pos_ch = round(pos_ch) + aux;
	}

	if (game->ray[r].ray_at == 1) 
		pos_ch++;
	if (game->ray[r].ray_at == 4) 
		pos_ch--;

	game->ray[r].hit_fh = pos_fh;
	game->ray[r].hit_ch = pos_ch;
	printf("%i(fh, ch): %f, %f\n", r, pos_fh, pos_ch);
/*
	if (pos_fh < 0 || pos_fh >= game->size_f || pos_ch < 0 || pos_ch >= game->size_c)
		valid = 1;
	//printf("tangle->%f\n", tangle);
	//printf("valid->%i\n", valid);	
	while (valid != 1 && !is_wall((int)pos_fh, (int)pos_ch, game)) 
	{
		if (game->ray[r].ray_angle > M_PI)
			pos_fh -= 1;
		else
			pos_fh += 1;
		if (game->ray[r].ray_angle > M_PI / 2 || game->ray[r].ray_angle < (3 * M_PI / 2)) 
			pos_ch -= tangle;
		else
			pos_ch += tangle;
		if (pos_fh < 0 || pos_fh >= game->size_f|| pos_ch < 0 || pos_ch >= game->size_c)
			valid = 1;
	}

	printf("HIT%i(fh, ch): %f, %f\n", r, pos_fh, pos_ch);
*/
//	tangle = tan(game->ray[r].ray_angle);
	pos_cv = game->player.c - 0.5;
	if (game->ray[r].ray_angle > (3 * M_PI / 2) || game->ray[r].ray_angle < (M_PI / 2))
		pos_cv++;
	pos_fv = game->player.f + (0.5 / tangle);
	if (game->ray[r].ray_at == 2)
	{
		aux = round(pos_fv) - pos_fv;
		pos_fv = round(pos_fv) + aux;
		pos_fv++;
	}
	if (game->ray[r].ray_at == 1) 
		pos_fv--;
	game->ray[r].hit_fv = pos_fv;
	game->ray[r].hit_cv = pos_cv;
	printf("%i(fv, cv): %f, %f\n", r, pos_fv, pos_cv);
/*
	valid = 0;
	if (pos_fv < 0 || pos_fv >= game->size_f || pos_cv < 0 || pos_cv >= game->size_c)
		valid = 1;
//	printf("valid->%i\n", valid);
//	printf("tangle->%f\n", tangle);
	while (valid != 1 && !is_wall((int)pos_fv, (int)pos_cv, game)) 
	{
		if (tangle == 0)
			;
		else if (game->ray[r].ray_angle > M_PI)
			pos_fv -= 1 / tangle;
		else
			pos_fv += 1 / tangle;
		if (game->ray[r].ray_angle > M_PI / 2 || game->ray[r].ray_angle < (3 * M_PI / 2)) 
			pos_cv -= 1;
		else
			pos_cv += 1;
		if (pos_fv < 0 || pos_fv >= game->size_f || pos_cv < 0 || pos_cv >= game->size_c)
			valid = 1;
	}
	printf("HIT%i(fv, cv): %f, %f\n", r, pos_fv, pos_cv);
*/
/*
	printf("M_PI / 2 = %f\n", (M_PI/2));
	printf("M_PI  = %f\n", (M_PI));
	printf("3M_PI / 2  = %f\n", (3 * M_PI/2));
	printf("2M_PI  = %f\n", (2 * M_PI));
*/

	return (0);
}

void	hit_pixel(t_game *game, int r, int	color_one, int	color_two)
{
	mlx_pixel_put(game->mlx.mlx, game->mlx.window, game->ray[r].hit_cv* 30,
			game->ray[r].hit_fv * 30, color_one);
	mlx_pixel_put(game->mlx.mlx, game->mlx.window, game->ray[r].hit_ch * 30,
			game->ray[r].hit_fh * 30, color_two);
}
