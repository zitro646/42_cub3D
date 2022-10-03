/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:22:07 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/03 11:35:12 by potero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_textures(t_game *game)
{	
	game->texture.image = mlx_xpm_file_to_image(game->mlx.mlx, game->north_texture,
							&game->texture.width, &game->texture.height);
	if (!game->texture.image)
	{
		//Hay que hacer freez
		ft_putstr_fd("Error loading textures\n", 2);
		exit(1);
	}
	game->texture.add = mlx_get_data_addr(game->texture.image,
			&game->texture.bpp, &game->texture.length, &game->texture.endian);
}

void	put_pixel(t_image *image, int c, int f, int color)
{
	char	*dst;

	dst = image->add + (f * image->length + c * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

