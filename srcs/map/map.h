/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 08:34:09 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/08/30 16:32:25 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

t_data_map	*mapreader(char *str_dir);
int			mapcheck(t_data_map *map);
int			get_file_height(char *str);
int			get_matrix_height(char **matrix);
t_list		**create_objectlist(t_list **list, char **show_map);
t_list		**create_playerlist(t_list **player, char **show_map, int y_max);

//Visualize tools
void		show_data(t_data_map	*data);
void		see_matrix(char **map);

//Parse map
void		resize_map(t_data_map	*data, char **map, int y, int i);
void		switch_chars_on_map(t_data_map	*data, char change, char *newchar);

//Free data
void		free_all(t_data_map *data_map);
void		free_matrix(char **matrix, int opt_size);

#endif
