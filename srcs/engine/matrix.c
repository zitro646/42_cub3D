/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:26:44 by potero-d          #+#    #+#             */
/*   Updated: 2022/10/10 12:18:29 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_matrix(char **file, int f, int c, t_matrix **matrix)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (i < f)
	{
		str = file[i];
		j = 0;
		matrix[i] = calloc(sizeof(t_matrix) * c, 1);
		if (!matrix[i])
			exit (0);
		while (j < c)
		{
			matrix[i][j].value = str[j];
			j++;
		}
		free(str);
		i++;
	}
}
/*
void	free_my_matrix(t_matrix *matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
*/
