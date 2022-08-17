/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:36:19 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/01/04 10:22:30 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*aux;
	t_list	*aux2;

	aux = *lst;
	while (aux != 0)
	{
		aux2 = aux->next;
		aux->x_axis = 0;
		aux->y_axis = 0;
		aux->type = 0;
		free(aux);
		aux = aux2;
	}
	*lst = 0;
}
