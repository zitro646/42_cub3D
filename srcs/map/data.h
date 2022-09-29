/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 08:34:09 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/09/29 11:32:41 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

t_data_map	*mapreader(char *str_dir);


//Get sizes of File / Matrix
int			get_file_height(char *str);
int			get_matrix_height(char **matrix);
int			get_matrix_max_size(char **array);

//Transform path variables
char		**get_infile_variables(char **file_data, char **identicators);

//Check Data collected is valid
int			data_check(t_data_map *data); //Primary checker
int			check_paths(t_data_map *data);
int			check_player_on_map(t_data_map *data, char *player_type);
int			check_map_no_strange_chars(char **map, char *acceptable_chars);
int			check_map_closed(t_data_map *data, int count, \
								char *aceptable_chars);

//Visualize tools
void		show_data(t_data_map	*data);
void		see_matrix(char **map);

//Parse map
void		flatten_map(t_data_map	*data, char **map, int y, int i);
void		resize_map(t_data_map	*data, char **map, int y, int i);
void		switch_chars_on_map(t_data_map	*data, char change, char *newchar);

//Free data
void		free_all(t_data_map *data_map);
void		free_matrix(char **matrix, int opt_size);

#endif
