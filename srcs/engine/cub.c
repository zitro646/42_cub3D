/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:20:10 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/04 11:49:39 by potero           ###   ########.fr       */
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
	game.matrix = calloc(sizeof(t_matrix *) * f , 1);
	if (!game.matrix)
		return (0);
	init(&game, data);
	start_game(&game);
	player_data(&game);
	window(&game, 0);
	hook_loop(&game);
	return (0);
}

int	colour_is_valid(char *str)
{
	char	**aux_str;
	int		num;
	int		i;
	int		tam;
	int		check;

	check = 1;
	i = 0;
	aux_str = ft_split(str, ',');
	tam = get_matrix_height(aux_str);
	while (i < tam)
	{
		num = ft_atoi(aux_str[i]);
		if (num == 0 && ft_strncmp(aux_str[i], "0", ft_strlen(aux_str[i])))
			check = 0;
		if (num < 0 || num > 255)
			check = 0;
			i++;
	}
	if (tam != 3)
		check = 0;
	free_matrix(aux_str, 0);
	return (check);
}

int	get_colour(char *str)
{
	int		colour;
	char	**aux_str;
	if (str == NULL || !colour_is_valid(str))
		return(0);
		aux_str = ft_split(str, ',');
	colour = (ft_atoi(aux_str[0]) << 16 | ft_atoi(aux_str[1]) << 8 | ft_atoi(aux_str[2]));
	free_matrix(aux_str, 0);
	return (colour);
}

void	init(t_game *game, t_data_map *data)
{
	create_matrix(data->showmap, game->size_f, game->size_c, game->matrix);
	game->player.speed_m = 1;
	game->player.speed_t = (M_PI * 2) / 8;
	game->width = 800;
	game->height = 800;
	game->diff_angle = (M_PI / 2) / game->width;
	game->ray = calloc(sizeof(t_ray) * game->width, 1);
	game->mlx.mlx = mlx_init();	
	game->mlx.screen = mlx_new_window(game->mlx.mlx, game->height, game->width, "cub3D"); 
	game->mlx.window = mlx_new_window(game->mlx.mlx,
			(game->size_c * 30), (game->size_f * 30), "minimap");

	game->scrn.image = mlx_new_image(game->mlx.mlx, game->width, game->height);
	game->mnmap.image = mlx_new_image(game->mlx.mlx, (game->size_c * 30), (game->size_f * 30));
	game->scrn.add = mlx_get_data_addr(game->scrn.image, &game->scrn.bpp,
					&game->scrn.length, &game->scrn.endian);
	game->mnmap.add = mlx_get_data_addr(game->mnmap.image, &game->mnmap.bpp,
					&game->mnmap.length, &game->mnmap.endian);

	game->floor_color = get_colour(data->_floor_colour_path);
	game->roof_color = get_colour(data->_roof_colour_path);
	game->north_texture = data->_north_texture_path;
	game->east_texture = data->_east_texture_path;
	game->south_texture = data->_south_texture_path;
	game->west_texture = data->_west_texture_path;
	load_textures(game);
}

int	hook_loop(t_game *game)
{
	
	mlx_hook(game->mlx.window, 2, (1L << 0), advance, game);
	mlx_hook(game->mlx.window, 3, (1L << 1), stop, game);
	mlx_hook(game->mlx.window, 17, (1L << 17), close_esc, game);

	mlx_hook(game->mlx.screen, 2, (1L << 0), advance, game);
	mlx_hook(game->mlx.screen, 3, (1L << 1), stop, game);
	mlx_hook(game->mlx.screen, 17, (1L << 17), close_esc, game);
	mlx_loop(game->mlx.mlx);

	return (0);
}

int	close_esc(t_game *game)
{
	mlx_clear_window(game->mlx.mlx, game->mlx.window);
	mlx_destroy_window(game->mlx.mlx, game->mlx.window);
	
	mlx_clear_window(game->mlx.mlx, game->mlx.screen);
	mlx_destroy_window(game->mlx.mlx, game->mlx.screen);
//	free_my_matrix(*game->matrix);
	exit(0);
	return (0);
}
