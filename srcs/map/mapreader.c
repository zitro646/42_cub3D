/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapreader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 08:31:10 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/08/30 16:32:52 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h" 

static char	**read_filedata(char *str_dir, int y_max)
{
	int			fd;
	int			i;
	int			j;
	char		**show_map;

	i = 0;
	show_map = ft_calloc(sizeof(char *), y_max + 1);
	fd = open(str_dir, O_RDONLY);
	show_map[i] = get_next_line(fd);
	i = 0;
	while (show_map[i])
	{
		j = 0;
		while (show_map[i][j] != '\0')
		{
			if (show_map[i][j] == '\n')
				show_map[i][j] = '\0';
			j++;
		}
		i++;
		show_map[i] = get_next_line(fd);
	}
	close(fd);
	return (show_map);
}

static	char	*get_var(char **file_data, char *id)
{
	char	*aux;
	char	*aux2;
	int		i;

	i = 0;
	aux = "";
	while (file_data[i])
	{
		if (ft_strnstr(file_data[i], id, ft_strlen(file_data[i])) != NULL)
		{
			aux2 = ft_strjoin(aux, file_data[i]);
			ft_bzero(file_data[i], ft_strlen(file_data[i]));
			file_data[i][0] = '\0';
			return (aux2);
		}
		i++;
	}
	return (NULL);
}

static	char	**get_infile_variables(char **file_data, char **identicators)
{
	char	**values;
	int		i;

	i = 0;
	values = ft_calloc(sizeof(char *), 6 + 1);
	while (identicators[i])
	{
		values[i] = get_var(file_data, identicators[i]);
		i++;
	}
	return (values);
}

static void	add_data_map(t_data_map	*map, char **infile_var)
{
	map->_north_texture_path = ft_strjoin(infile_var[0], "");
	map->_south_texture_path = ft_strjoin(infile_var[1], "");
	map->_east_texture_path = ft_strjoin(infile_var[2], "");
	map->_west_texture_path = ft_strjoin(infile_var[3], "");
	map->_floor_colour_path = ft_strjoin(infile_var[4], "");
	map->_roof_colour_path = ft_strjoin(infile_var[5], "");
}

t_data_map	*mapreader(char *str_dir)
{
	t_data_map	*map;
	char		**_crudedata;
	char		**identificators;
	char		**infile_var;

	if (get_file_height(str_dir) < 1)
		return (0);
	map = ft_calloc(sizeof(t_data_map), 1);
	identificators = ft_split("NO SO WE EA F C", ' ');
	map->height = get_file_height(str_dir);
	_crudedata = read_filedata(str_dir, map->height);
	infile_var = get_infile_variables(_crudedata, identificators);
	add_data_map(map, infile_var);
	resize_map(map, _crudedata, 0, 0);
	map->height = get_matrix_height(map->showmap);
	switch_chars_on_map(map, '\t', "    ");
	free_matrix(_crudedata, 0);
	free_matrix(identificators, 0);
	free_matrix(infile_var, 6);
	return (map);
}
// map->player = create_playerlist(map->player, map->showmap, map->height);
	// map->enemy = create_enemylist(map->enemy, map->showmap);
