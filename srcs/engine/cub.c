/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:20:10 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/06 12:42:49 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cube(t_data_map *data)
{
	int		x;
	int		y;
	t_game	game;

	if (argc != 2)
	{
		printf("Error\nWrong number of arguments\n");
		exit(0);
	}
	x = 0;
	matrix_size(argv[1], &x, &y);
	game.matrix = malloc(sizeof(t_matrix *) * x + 1);
	game.matrix[x] = 0;
	if (!game.matrix)
		return (0);
	init(&game, x, y, argv[1]);
	game.size_x = x;
	game.size_y = y;
	image(&game);
	//screen_game(&game, x, y);
	hook_loop(&game);
}

void	init(t_game *game, int x, int y, char *argv)
{
	create_matrix(argv, x, y, game->matrix);
	game->player.speed_m = 0.3;	//pixels
	game->player.speed_t = 3 *(M_PI / 180);	//grados
	game->width = 1024;
	game->height = 1280;
	game->mlx.mlx = mlx_init();
	game->mlx.window = mlx_new_window(game->mlx.mlx, (y * 15), (x * 15), "minimap");
	//game->mlx.screen = mlx_new_window(game->mlx.mlx, game->height, game->width, "cub3D"); 
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
