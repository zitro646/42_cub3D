/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:17:49 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/03 11:26:55 by potero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<fcntl.h>
# include<math.h>
# include "../map/data.h"
# include "structs.h"
# include <mlx.h>

/*Cub*/
int		cube(t_data_map *data);
void	init(t_game *game, t_data_map *data);
int		hook_loop(t_game *game);
int		close_esc(t_game *game);
int		get_colour(char *str);
int		colour_is_valid(char *str);

/*Matrix*/
void	create_matrix(char **file, int f, int c, t_matrix **matrix);
void	free_my_matrix(t_matrix *matrix);

/*Player Data*/
void	player_data(t_game *game);

//void	player_pixel(t_game *game, int color);
//void	wall_floor_pixel(t_game *game, int pos_f, int pos_c, int color);
//int		pos_is_wall( int x_pixel, int y_pixel, t_game *game);
//void	ray_vision(t_game *game, int color);
//void	player_vision_cone(t_game *game, int color);
//void	minimap(t_game *game);

/*Screen*/
void	screen_game(t_game *game);
void	screen_game_r(t_game *game, int r);
void	start_game(t_game *game);

/*Window*/
void	ray_vision(t_game *game, int color);
void	player_pixel(t_game *game, int color, double f, double c);
void	wall_floor_pixel(t_game *game, int pos_f, int pos_c, int color);
void	window(t_game *game, int start);

/*Key hook*/
int		advance(int key_code, t_game *game);
int		stop(int key_code, t_game *game);
void	hook(t_game *game, int key_code);

/*Angle*/

void	angle(t_game *game);
void	looking_at(t_game *game);
double	new_angle(double angle);
void	ray_at(t_game *game, int r);

/*Ray*/
void	ray(t_game *game);
int		is_wall( int f, int c, t_game *game);

/*RayDDA*/
double  ray_vision_dda(t_game *game, double angle, int r);

/*DDA*/
double	dda(t_game *game, int r);
void	hit_pixel(t_game *game, int r, int color_one, int colot_two);

/*Minimap*/
void	minimap(t_game *game);
void	ray_vision_minimap(t_game *game, int color);
void	player_minimap(t_game *game, int color);
void	wall_floor_minimap(t_game *game, int pos_f, int pos_c, int color);

/*Texture*/
void	load_textures(t_game *game);
void	put_pixel(t_image *image, int c, int f, int color);

#endif
