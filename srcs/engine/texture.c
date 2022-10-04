/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:22:07 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/04 16:37:05 by potero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_textures(t_game *game)
{
	int	i;
	game->texture[0].image = mlx_xpm_file_to_image(game->mlx.mlx, game->north_texture,
							&game->texture[0].width, &game->texture[0].height);
	game->texture[1].image = mlx_xpm_file_to_image(game->mlx.mlx, game->east_texture,
							&game->texture[1].width, &game->texture[1].height);
	game->texture[2].image = mlx_xpm_file_to_image(game->mlx.mlx, game->south_texture,
							&game->texture[2].width, &game->texture[2].height);
	game->texture[3].image = mlx_xpm_file_to_image(game->mlx.mlx, game->west_texture,
							&game->texture[3].width, &game->texture[3].height);
	i = 0;
	while (i < 4)
	{
		if (!game->texture[i].image)
		{
			//Hay que hacer freez
			ft_putstr_fd("Error loading texture", 2);
			write(2, "%i\n", 2);
			exit(1);
		}
		i++;
	}
	game->texture[0].add = mlx_get_data_addr(game->texture[0].image,
			&game->texture[0].bpp, &game->texture[0].length, &game->texture[0].endian);
	game->texture[1].add = mlx_get_data_addr(game->texture[1].image,
			&game->texture[1].bpp, &game->texture[1].length, &game->texture[1].endian);
	game->texture[2].add = mlx_get_data_addr(game->texture[2].image,
			&game->texture[2].bpp, &game->texture[2].length, &game->texture[2].endian);
	game->texture[3].add = mlx_get_data_addr(game->texture[3].image,
			&game->texture[3].bpp, &game->texture[3].length, &game->texture[3].endian);
	printf("All textures load\n");
	i = -1;
	while (++i < 4)
	{
		printf("length[%i]->%d\n", i, game->texture[i].length); 
		printf("width[%i]->%d\n", i, game->texture[i].width); 
		printf("height[%i]->%d\n", i, game->texture[i].height);
		printf("bpp[%i]->%d\n", i, game->texture[i].bpp);
	}
}

void	put_pixel(t_image *image, int c, int f, int color)
{
	char	*dst;

	dst = image->add + (f * image->length + c * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

