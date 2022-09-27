/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:26:44 by potero-d          #+#    #+#             */
/*   Updated: 2022/09/27 11:27:41 by potero-d         ###   ########.fr       */
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
		matrix[i] = calloc(sizeof(t_matrix) * c , 1);
		if (!matrix[i])
			exit (0);
		while (j < c)
		{
			matrix[i][j].value = str[j];
			printf("%c", matrix[i][j].value);
			j++;
		}
		printf(".\n");
		free(str);
		i++;
	}
}
