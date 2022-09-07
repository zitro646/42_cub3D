/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:26:44 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/07 12:48:12 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_matrix(char **file, int x, int y, t_matrix **matrix)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (i < x)
	{
		str = file[i];
		j = 0;
		matrix[i] = calloc(sizeof(t_matrix) * y , 1);
		if (!matrix[i])
			exit (0);
		while (j < y)
		{
			matrix[i][j].pos_x = i;
			matrix[i][j].pos_y = j;
			matrix[i][j].value = str[j];
			j++;
		}
		free(str);
		i++;
	}
	printf("SALGO :)\n");
}
