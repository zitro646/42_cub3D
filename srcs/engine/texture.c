/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:22:07 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/29 14:04:43 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_textures(t_game *game)
{	
	game->texture.image = mlx_xpm_file_to_image(game->mlx, game->north_texture, 400, 400);
	if (!game->texture.iamge)
	{
		//Hay que hacer freez
		ft_putstr_fd("Error loading textures\n", 2);
		exit(1);
	}
	game->texture.add = mlx_get_data_addr(game->texture.image,
			&game->texture.bbp, &game->texture.length, &game->texture.endian);
}
