/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:17:49 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/11 12:59:52 by potero-d         ###   ########.fr       */
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
void	init_color_and_textures(t_game *game, t_data_map *data);
int		hook_loop(t_game *game);
int		close_esc(t_game *game);

/*Matrix*/
void	create_matrix(char **file, int f, int c, t_matrix **matrix);
void	free_my_matrix(t_matrix **matrix);

/*Player Data*/
void	player_data(t_game *game);

/*Screen*/
void	screen_game(t_game *game);
void	screen_game_r(t_game *game, int r);
void	start_game(t_game *game);
void	frame(t_game *game);

/*Window*/
void	ray_vision(t_game *game, int color);
void	player_pixel(t_game *game, int color, double f, double c);
void	wall_floor_pixel(t_game *game, int pos_f, int pos_c, int color);
void	window(t_game *game, int start);

/*Key hook*/
int		advance(int key_code, t_game *game);
int		stop(int key_code, t_game *game);
int		movement(t_game *game, double f, double c);
void	hook(t_game *game, int key_code);
void	finish_hook(double new_c, double new_f, t_game *game);

/*Angle*/

void	angle(t_game *game);
void	looking_at(t_game *game);
double	new_angle(double angle);
void	ray_at(t_game *game, int r);
int		is_angle(float angle, float angle_2);

/*Ray*/
void	ray(t_game *game);
int		is_wall( int f, int c, t_game *game);

/*RayDDA*/
int		inside_matrix(t_game *game, int f, int c);
float	distance(float ax, float ay, float bx, float by);
int		new_pos_is_wall( int y, int x, t_game *game);
double	ray_vision_dda(t_game *game, double angle, int r);
int		hit_check(int my, int mx, float angle, t_game *game);

/*DDA Horizontal*/
float	ray_vision_horizontal(t_game *game, double angle, int r, float aTan);

/*DDA Vertical*/
float	ray_vision_vertical(t_game *game, double angle, int r, float nTan);

/*Minimap*/
void	minimap(t_game *game);
void	ray_vision_minimap(t_game *game, int color);
void	player_minimap(t_game *game, int color);
void	wall_floor_minimap(t_game *game, int pos_f, int pos_c, int color);

/*Texture*/
void	load_textures(t_game *game);
void	put_pixel(t_image *image, int c, int f, int color);
void	add_textures(t_game *game);

/*Color*/
int		get_colour(char *str);
int		colour_is_valid(char *str);

#endif
