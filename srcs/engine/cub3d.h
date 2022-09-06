/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:17:49 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/06 12:41:54 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
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
void	init(t_game *game, int x, int y, char *argv);
int		hook_loop(t_game *game);
int		close_esc(t_mlx *mlx);

/*Marix Size*/
void	matrix_size(char *file, int *x, int *y);
void	matrix_size_y(char *file, int x, int *y);

/*Matrix*/
void	create_matrix(char *file, int x, int y, t_matrix **matrix);

/*Map*/
void	image(t_game *game);
void	player_pixel(t_game *game, int color);
void	wall_floor_pixel(t_game *game, int pos_x, int pos_y, int color);

/*Screen*/
void	screen_game(t_game *game, int x, int y);

/*Key hook*/
int		advance(int key_code, t_game *game);
int		stop(int key_code, t_game *game);
void	hook(t_game *game, int key_code);

#endif