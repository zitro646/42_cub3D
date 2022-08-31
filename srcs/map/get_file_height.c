/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:10:31 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/08/31 12:51:30 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

int	get_file_height(char *str)
{	
	int		count;
	int		fd;
	char	*archive;

	count = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	archive = 0;
	archive = get_next_line(fd);
	while (archive)
	{
		free(archive);
		archive = get_next_line(fd);
		count++;
	}
	close(fd);
	return (count);
}

int	get_matrix_height(char **matrix)
{	
	int		count;

	count = 0;
	while (matrix[count])
		count++;
	return (count);
}
