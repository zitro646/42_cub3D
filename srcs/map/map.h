/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 08:34:09 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/25 09:24:44 by mortiz-d         ###   ########.fr       */
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
t_list		**create_objectlist(t_list **list, char **show_map);
t_list		**create_playerlist(t_list **player, char **show_map, int y_max);
#endif
