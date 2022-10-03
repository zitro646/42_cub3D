/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:15:53 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/03 11:23:01 by potero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
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

typedef struct s_ray
{
	int		ray;
	double	ray_angle;
	double	hit_f;
	double	hit_c;
//	double	hit_fh;
//	double	hit_ch;
//	double	hit_fv;
//	double	hit_cv;
	double	distance;
	double	point;
	double	wall;
	int		ray_at;
	int		hor;
	int		ver;
}	t_ray;

typedef struct s_texture
{
	void	*image;
	char	*add;
	int		width;
	int		height;
	int		endian;
	int		bpp;
	int		length;
}	t_texture;

typedef struct s_image
{
	void	*image;
	char	*add;
	int		width;
	int		height;
	int		endian;
	int		bpp;
	int		length;
}	t_image;

typedef struct s_game
{
	t_matrix	**matrix;
	t_ray		*ray;
	t_mlx		mlx;
	t_player	player;
	t_texture	texture;
	t_image		scrn;
	t_image		mnmap;
	double		diff_angle;
	int			height;
	int			width;
	int			size_f;
	int			size_c;
	int			floor_color;
	int			roof_color;
	char		*north_texture;

}	t_game;

#endif
