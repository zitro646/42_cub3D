/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:49:01 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/14 15:14:26 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				resta;
	unsigned long	numero;

	resta = 0;
	numero = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' \
	|| *str == '\f' || *str == '\r' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			resta++;
	}
	while (*str >= '0' && *str <= '9')
	{
		numero = (numero * 10) + (*str++ - '0');
		if ((numero > 2147483647 && resta == 0) || \
			(numero > 2147483648 && resta > 0))
			return (0);
	}
	if (*str != '\0')
		return (0);
	if (resta > 0)
		return ((int)numero * -1);
	return ((int)numero);
}
