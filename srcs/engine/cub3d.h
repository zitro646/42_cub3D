/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:17:49 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/22 03:03:25 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define RED 0xFF0000
# define PINK 0xFF00FF
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define LIGHT_BLUE 0x00FFFF
# define WHITE 0xFFFFFF
# define ORANGE 0xFF6600
# define CUB3D_H
# define CUB3D_H
# define CUB3D_H
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<fcntl.h>
# include<math.h>
# include "../libft/libft.h"
# include "structs.h"
# include <mlx.h>

/*Cub*/
int		cube(t_data_map *data);
void	init(t_game *game, int x, int y, char **map);
int		hook_loop(t_game *game);
int		close_esc(t_mlx *mlx);

/*Matrix*/
void	create_matrix(char **file, int x, int y, t_matrix **matrix);

/*Map*/
void	image(t_game *game);
void	player_pixel(t_game *game, int color);
void	wall_floor_pixel(t_game *game, int pos_x, int pos_y, int color);
int		pos_is_wall( int x_pixel, int y_pixel, t_game *game);
void	ray_vision(t_game *game, int color, double angle);
void	player_vision_cone(t_game *game, int color);

/*Screen*/
void	screen_game(t_game *game);
void	start_game(t_game *game);

/*Key hook*/
int		advance(int key_code, t_game *game);
int		stop(int key_code, t_game *game);
void	hook(t_game *game, int key_code);

/*Angle*/

void	angle(t_game *game);
void	looking_at(t_game *game);
double	new_angle(double angle);
void	ray_at(t_game *game);

/*Ray*/
void	init_ray(t_game *game);
void	ray(t_game *game);

/*RayDDA*/
int		new_pos_is_wall( int y, int x, t_game *game);
int		horizontal_check(int my, int mx, float  angle, t_game *game);
void	correct_horizontal_hit(float *pixel_y, float *pixel_x, float angle,t_game *game);
int		vertical_check(int my, int mx, float  angle, t_game *game);
void	correct_vertical_hit(float *pixel_y, float *pixel_x, float angle,t_game *game);
void 	centralize_hit_point(float *pixel_y, float *pixel_x, float angle,t_game *game);
void	ray_vision_dda(t_game *game, int color, double angle);
#endif
