/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:42:57 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/08/31 12:51:21 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static int	str_is_identificator(char *str, char **identificators)
{
	int	i;

	i = 0;
	while (identificators[i])
	{
		if (ft_strnstr(str, identificators[i], ft_strlen(str)))
			return (1);
		i++;
	}
	return (0);
}

static	char	*get_var(char **file_data, \
							char *id, char **identificators)
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
		else if (file_data[i][0] != '\0')
			if (!str_is_identificator(file_data[i], identificators))
				break ;
		i++;
	}
	return (NULL);
}

char	**get_infile_variables(char **file_data, char **identicators)
{
	char	**values;
	int		i;

	i = 0;
	values = ft_calloc(sizeof(char *), 6 + 1);
	while (identicators[i])
	{
		values[i] = get_var(file_data, identicators[i], identicators);
		i++;
	}
	return (values);
}
