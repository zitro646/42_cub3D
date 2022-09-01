/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:20:10 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/01 14:44:09 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cube(t_data_map *data)
{
	int		x;
	int		y;
	t_game	game;

	printf ("HOLA ESTO ES UNA PRUEBA \n");
	x = data->height;
	y = data->max_width;
	//matrix_size(argv[1], &x, &y);
	printf("WOLOLOLO Map size->(%d, %d)\n", x, y);
	// game.matrix = NULL;
	game.matrix = calloc(sizeof(t_matrix *) * x , 1);
	// game.matrix[x] = 0;
	if (!game.matrix)
		return (0);
	init(&game, x, y, data->showmap);
	printf("4\n");
	image(&game, x, y);
	printf("5\n");
	//screen_game(&game, x, y);
	hook_loop(&game);
	return (0);
}

void	init(t_game *game, int x, int y, char **map)
{
	create_matrix(map, x, y, game->matrix);
	printf("TEST se ha creado la matrix\n");
/*	dir_x_y(game);
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
	game->player.speed_m = 3;	//pixels
	game->player.speed_t = 3 *(M_PI / 180);	//grados
	game->player.angle = 0;		//rad
	game->width = 1024;
	game->height = 1280;*/
	game->mlx.mlx = mlx_init();
	printf("1\n");
	game->mlx.window = mlx_new_window(game->mlx.mlx, (y * 15), (x * 15), "minimap");
	printf("2\n");
	//game->mlx.screen = mlx_new_window(game->mlx.mlx, game->height, game->width, "cub3D"); 
	assets(&game->mlx);
	printf("3\n");
}

int advance(int key_code, t_game *game)
{
	if (key_code == 1 || key_code == 2 || key_code == 3 || key_code == 13)
		game->player.advance = 1;
	else if (key_code == 123 || key_code == 124)
		game->player.turn = 1;
	return (0);
}

int	hook_loop(t_game *game)
{
	mlx_key_hook(game->mlx.window, key_event, game);
//	mlx_hook(game->mlx.window, 2, (1L << 0), key_event, game);
//	mlx_hook(game->mlx.window, 3, (1L << 1), key_event, game);
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
