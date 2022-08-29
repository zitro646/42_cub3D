/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:06:32 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/08/29 19:06:56 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include "../map/map.h"
// # include <mlx.h>
# include "../minilibx/mlx.h"
// # include "../minilibx/mlx_int.h"
// # include "../minilibx/mlx_new_window.h"
// # include "../minilibx/mlx_opengl.h"
// # include "../minilibx/mlx_png.h"

//Start window
void		make_window(t_data_map *data_map);
t_window	*init_window(void);

//Event keys
// int			key_hook(int key_code, t_data_map *data_map);
// int			ft_red_cross(t_data_map *data_map);


#endif