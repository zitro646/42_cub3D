/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:35:36 by potero-d          #+#    #+#             */
/*   Updated: 2022/08/30 12:04:58 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	matrix_size(char *file, int *x, int *y)
{
	char	*str;
	int		map;
	int		i;

	map = open(file, O_RDONLY);
	if (map == -1)
		exit(0);
//		error_map_no(0);
	i = 0;
	str = get_next_line(map);
	while (str != 0)
	{
		i++;
		free(str);
		str = get_next_line(map);
	}
	free(str);
	*x = i;
	close(map);
	matrix_size_y(file, *x, y);
}

void	matrix_size_y(char *file, int x, int *y)
{
	char	*str;
	int		map;
	int		i;
	int		aux;

	map = open(file, O_RDONLY);
	if (map == -1)
		exit(0);
		//error_map_no(0);
	*y = 0;
	i = 0;
	while (i < x)
	{
		str = get_next_line(map);
		aux = ft_strlen(str);
		free(str);
		if (aux > *y)
			*y = aux;
		i++;
	}
	*y = *y - 1;
	close(map);
}
