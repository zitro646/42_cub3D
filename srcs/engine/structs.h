/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:15:53 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/08 10:26:00 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3d.h"

typedef struct s_matrix
{
	int		pos_x;
	int		pos_y;
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
	double	x;
	double	y;
	double	advance;
	double	turn;
	double	angle;
	double	angle_view;
	double	speed_m;
	double	speed_t;
	int		looking_at;
}	t_player;

typedef struct s_ray
{
	int		ray;
	double	ray_angle;
	double	hit_x;
	double	hit_y;
	double	step_x;
	double	step_y;
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
	int			size_x;
	int			size_y;
}	t_game;

#endif
