/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:15:53 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/03 11:36:02 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define VERTICAL_HIT 1
# define HORIZONTAL_HIT 2

# define STRUCTS_H
# include "cub3d.h"

typedef struct s_matrix
{
	int		pos_f;
	int		pos_c;
	char	value;
}	t_matrix;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*screen;
}	t_mlx;


typedef struct s_player
{
	double	f;
	double	c;
	double	advance;
	double	turn;
	double	angle;
	double	angle_view;
	double	speed_m;
	double	speed_t;
	int		looking_at;
}	t_player;

typedef struct s_image
{
	char **img_colours;
	char **img_chars;
	int *color_values;
	int n_colours;
	int n_pixel_char;
	int n_colums;
	int n_files;
}	t_image;

typedef struct s_ray
{
	int		ray;
	double	ray_angle;
	double	hit_f;
	double	hit_c;
	double	distance;
	double	point;
	double	wall;
	int		ray_at;
	int		side_hit;
	int		pixel_hit;
}	t_ray;

typedef struct s_game
{
	t_matrix	**matrix;
	t_ray		*ray;
	t_mlx		mlx;
	t_player	player;
	double		diff_angle;
	int			height;
	int			width;
	int			size_f;
	int			size_c;
	int			floor_colour;
	int			roof_colour;
	t_image		*n_wall;
	t_image		*s_wall;
	t_image		*e_wall;
	t_image		*w_wall;
}	t_game;

#endif
