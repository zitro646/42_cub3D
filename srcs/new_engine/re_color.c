/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:48:19 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/10/18 13:01:33 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	colour_is_valid(char *str)
{
	char	**aux_str;
	int		num;
	int		i;
	int		tam;
	int		check;

	check = 1;
	i = 0;
	aux_str = ft_split(str, ',');
	tam = get_matrix_height(aux_str);
	while (i < tam)
	{
		num = ft_atoi(aux_str[i]);
		if (num == 0 && ft_strncmp(aux_str[i], "0", ft_strlen(aux_str[i])))
			check = 0;
		if (num < 0 || num > 255)
			check = 0;
			i++;
	}
	if (tam != 3)
		check = 0;
	free_matrix(aux_str, 0);
	return (check);
}

int	get_colour(char *str)
{
	int		colour;
	char	**aux_str;

	if (str == NULL || !colour_is_valid(str))
		return (0);
	aux_str = ft_split(str, ',');
	colour = (ft_atoi(aux_str[0]) << 16 | ft_atoi(aux_str[1]) << 8
			| ft_atoi(aux_str[2]));
	free_matrix(aux_str, 0);
	return (colour);
}
