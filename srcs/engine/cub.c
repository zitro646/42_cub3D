/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:20:10 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/08 15:42:22 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cube(t_data_map *data)
{
	int		x;
	int		y;
	t_game	game;

	x = data->height;
	y = data->max_width;
	game.size_x = x;
	game.size_y = y;
	printf("Test 1\n");
	//matrix_size(argv[1], &x, &y);
	// game.matrix = NULL;
	game.matrix = calloc(sizeof(t_matrix *) * x , 1);
	printf("Test 2\n");
	// game.matrix[x] = 0;
	if (!game.matrix)
		return (0);
	printf("Test 3\n");
	init(&game, x, y, data->showmap);
	printf("Test 4\n");
	image(&game);
	printf("Test 5\n");
	//screen_game(&game, x, y);
	hook_loop(&game);
	printf("Test 6\n");
	return (0);
}

void	init(t_game *game, int x, int y, char **map)
{
	create_matrix(map, x, y, game->matrix);
	game->player.speed_m = 0.1;	//pixels
	game->player.speed_t = (M_PI * 2) / 32;	//grados -> 5 *(M_PI / 180)
	game->width = 1024;
	game->height = 1280;
	game->diff_angle = (M_PI / 2) / game->width;
	game->ray = calloc(sizeof(t_ray) * game->width, 1);
	init_ray(game);
	game->mlx.mlx = mlx_init();
	game->mlx.screen = mlx_new_window(game->mlx.mlx, game->height, game->width, "cub3D"); 
	game->mlx.window = mlx_new_window(game->mlx.mlx, (y * 15), (x * 15), "minimap");
}

int	hook_loop(t_game *game)
{
	mlx_hook(game->mlx.window, 2, (1L << 0), advance, game);
	mlx_hook(game->mlx.window, 3, (1L << 1), stop, game);
	mlx_hook(game->mlx.window, 17, (1L << 17), close_esc, &game->mlx);
	mlx_loop(game->mlx.mlx);
	return (0);
}

int	close_esc(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->window);
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(0);
	return (0);
}
