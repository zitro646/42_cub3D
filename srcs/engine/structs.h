/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:15:53 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/11 13:12:22 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define M_SIZE 64
# define VERTICAL 1
# define HORIZONTAL 0
# define RED 0xFF0000
# define PINK 0xFF00FF
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define CYAN 0x00FFFF
# define WHITE 0xFFFFFF
# define ORANGE 0xFF6600
# define PURPLE 0x4B0082
# define DARK_PURPLE 0x3C0068
# define GREY 0x8C8C8C
# define DARK_GREEN 0x186A3B 
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
	int		wall_hit;
	double	distance;
	double	point;
	double	wall;
	int		ray_at;
	int		hor;
	int		ver;
	float	hx;
	float	hy;
	float	xo;
	float	yo;
	float	vx;
	float	vy;
	int		mx;
	int		my;
	float	rx;
	float	ry;
	float	dof;
	float	distv;
	float	disth;
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
	t_texture	texture[4];
	t_image		scrn;
	t_image		mnmap;
	t_image		minimap;
	double		f;
	double		diff_angle;
	int			height;
	int			width;
	int			size_f;
	int			size_c;
	int			floor_color;
	int			roof_color;
	char		*north_texture;
	char		*east_texture;
	char		*south_texture;
	char		*west_texture;
}	t_game;

#endif
