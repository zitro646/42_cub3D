/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:47:47 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/25 14:43:38 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char type, int x, int y)
{
	t_list	*lista;

	lista = malloc(sizeof(t_list));
	if (lista == 0)
		return (0);
	lista->type = type;
	lista->go_to_x = x;
	lista->go_to_y = y;
	lista->x_axis = x;
	lista->y_axis = y;
	lista->next = 0;
	lista->prev = 0;
	return (lista);
}
