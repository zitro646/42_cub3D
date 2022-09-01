/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:43:36 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/01 14:27:07 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assets(t_mlx *mlx)
{
	int	px;

	px = 50;
	mlx->img_n = mlx_xpm_file_to_image(mlx->mlx,
			"./srcs/assets/n.xpm", &px, &px);
	mlx->img_s = mlx_xpm_file_to_image(mlx->mlx,
			"./srcs/assets/s.xpm", &px, &px);
	mlx->img_e = mlx_xpm_file_to_image(mlx->mlx,
			"./srcs/assets/e.xpm", &px, &px);
	mlx->img_o = mlx_xpm_file_to_image(mlx->mlx,
			"./srcs/assets/o.xpm", &px, &px);
	mlx->img_f = mlx_xpm_file_to_image(mlx->mlx,
			"./srcs/assets/grey.xpm", &px, &px);
	mlx->img_w = mlx_xpm_file_to_image(mlx->mlx,
			"./srcs/assets/wall.xpm", &px, &px);
}
