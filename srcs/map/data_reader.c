/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 08:31:10 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/09/01 16:05:43 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h" 

static char	**read_filedata(char *str_dir, int y_max)
{
	int			fd;
	int			i;
	int			j;
	char		**new_map;

	i = 0;
	new_map = ft_calloc(sizeof(char *), y_max + 1);
	fd = open(str_dir, O_RDONLY);
	new_map[i] = get_next_line(fd);
	i = 0;
	while (new_map[i])
	{
		j = 0;
		while (new_map[i][j] != '\0')
		{
			if (new_map[i][j] == '\n')
				new_map[i][j] = '\0';
			j++;
		}
		i++;
		new_map[i] = get_next_line(fd);
	}
	close(fd);
	return (new_map);
}

int	get_matrix_max_size(char **array)
{
	int	x_max;
	int	i;
	int	j;

	i = 0;
	j = 0;
	x_max = 0;
	while (array[j])
	{
		while (array[j][i] != 0)
			i++;
		if (x_max < i)
			x_max = i;
		i = 0;
		j++;
	}
	return (x_max);
}

static void	add_data_variable_paths(t_data_map	*data, char **infile_var)
{
	if (get_matrix_height(infile_var) != 6)
	{
		data->_north_texture_path = NULL;
		data->_south_texture_path = NULL;
		data->_west_texture_path = NULL;
		data->_east_texture_path = NULL;
		data->_floor_colour_path = NULL;
		data->_roof_colour_path = NULL;
		return ;
	}
	data->_north_texture_path = ft_strjoin(\
			&ft_strnstr(infile_var[0], "NO", ft_strlen(infile_var[0]))[3], "");
	data->_south_texture_path = ft_strjoin(\
			&ft_strnstr(infile_var[1], "SO", ft_strlen(infile_var[1]))[3], "");
	data->_west_texture_path = ft_strjoin(\
			&ft_strnstr(infile_var[2], "WE", ft_strlen(infile_var[2]))[3], "");
	data->_east_texture_path = ft_strjoin(\
			&ft_strnstr(infile_var[3], "EA", ft_strlen(infile_var[3]))[3], "");
	data->_floor_colour_path = ft_strjoin(\
			&ft_strnstr(infile_var[4], "F", ft_strlen(infile_var[4]))[2], "");
	data->_roof_colour_path = ft_strjoin(\
			&ft_strnstr(infile_var[5], "C", ft_strlen(infile_var[5]))[2], "");

}

t_data_map	*mapreader(char *str_dir)
{
	t_data_map	*data;
	char		**_crudedata;
	char		**identificators;
	char		**infile_path_var;

	if (get_file_height(str_dir) < 1)
		return (0);
	data = ft_calloc(sizeof(t_data_map), 1);
	identificators = ft_split("NO SO WE EA F C", ' ');
	data->height = get_file_height(str_dir);
	_crudedata = read_filedata(str_dir, data->height);
	infile_path_var = get_infile_variables(_crudedata, identificators);
	add_data_variable_paths(data, infile_path_var);
	resize_map(data, _crudedata, 0, 0);
	data->height = get_matrix_height(data->showmap);
	data->max_width = get_matrix_max_size(data->showmap);
	flatten_map(data, data->showmap, 0, 0);
	switch_chars_on_map(data, '\t', "    ");
	free_matrix(_crudedata, 0);
	free_matrix(identificators, 0);
	free_matrix(infile_path_var, 6);
	return (data);
}
// map->player = create_playerlist(map->player, map->showmap, map->height);
	// map->enemy = create_enemylist(map->enemy, map->showmap);
