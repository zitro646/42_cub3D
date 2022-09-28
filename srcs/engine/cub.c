/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:20:10 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/28 11:47:23 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cube(t_data_map *data)
{
	int		f;
	int		c;
	t_game	game;

	f = data->height;
	c = data->max_width;
	game.size_f = f;
	game.size_c = c;
//	printf("(f,c)->%i, %i\n", f, c);
	game.matrix = calloc(sizeof(t_matrix *) * f , 1);
	if (!game.matrix)
		return (0);
	init(&game, f, c, data->showmap);
	start_game(&game);
	image(&game);
	hook_loop(&game);
	return (0);
}

void	init(t_game *game, int f, int c, char **map)
{
	create_matrix(map, f, c, game->matrix);
	game->player.speed_m = 1;
	game->player.speed_t = (M_PI * 2) / 8;
	game->width = 800;
	game->height = 800;
	game->diff_angle = (M_PI / 2) / game->width;
	game->ray = calloc(sizeof(t_ray) * game->width, 1);
	game->mlx.mlx = mlx_init();	
	game->mlx.screen = mlx_new_window(game->mlx.mlx, game->height, game->width, "cub3D"); 
//	game->mlx.window = mlx_new_window(game->mlx.mlx, (c * 30), (f * 30), "minimap");
}

int	hook_loop(t_game *game)
{
/*	
	mlx_hook(game->mlx.window, 2, (1L << 0), advance, game);
	mlx_hook(game->mlx.window, 3, (1L << 1), stop, game);
	mlx_hook(game->mlx.window, 17, (1L << 17), close_esc, &game->mlx);
*/	
	mlx_hook(game->mlx.screen, 2, (1L << 0), advance, game);
	mlx_hook(game->mlx.screen, 3, (1L << 1), stop, game);
	mlx_hook(game->mlx.screen, 17, (1L << 17), close_esc, &game->mlx);
	mlx_loop(game->mlx.mlx);

	return (0);
}

int	close_esc(t_mlx *mlx)
{
	/*
	mlx_clear_window(mlx->mlx, mlx->window);
	mlx_destroy_window(mlx->mlx, mlx->window);
	*/
	mlx_clear_window(mlx->mlx, mlx->screen);
	mlx_destroy_window(mlx->mlx, mlx->screen);
	exit(0);
	return (0);
}
