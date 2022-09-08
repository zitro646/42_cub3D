/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:24:16 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/09/08 13:10:04 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h" 

int	data_check(t_data_map *data)
{
	int		_error[4];

	if (data == NULL)
		return (0);
	_error[0] = check_map_closed(data, 0, "01NSWE");
	_error[1] = check_player_on_map(data, "NSWE");
	_error[2] = check_paths(data);
	_error[3] = check_map_no_strange_chars(data->showmap, "01NSWE ");
	if (_error[0] && _error[1] && _error[2] && _error[3])
		return (1);
	else
	{
		printf("Error ");
		if (!_error[0])
			printf("- Bad Enclosure ");
		if (!_error[1])
			printf("- Wrong Player Count ");
		if (!_error[2])
			printf("- No paths for textures ");
		if (!_error[3])
			printf("- Strange chars on map ");
		printf("\n");
	}
	return (0);
}
