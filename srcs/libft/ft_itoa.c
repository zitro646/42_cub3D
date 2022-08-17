/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:12:25 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/16 15:52:15 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	calcular_tamano(int n);
static char	*convertir_string(int n, int tam, char *array);

char	*ft_itoa(int n)
{
	int		tam;
	char	*str;

	tam = calcular_tamano(n);
	str = ft_calloc(sizeof(char), tam + 1);
	if (str == 0)
		return (0);
	str = convertir_string(n, tam, str);
	return (str);
}

static	int	calcular_tamano(int n)
{
	int		numero;
	int		tam;

	numero = n;
	tam = 1;
	if (numero == -2147483648)
	{
		tam++;
		numero /= 10;
	}
	if (n < 0)
	{
		tam++;
		numero *= -1;
	}
	while (numero > 9)
	{
		tam++;
		numero /= 10;
	}
	return (tam);
}

static char	*convertir_string(int n, int tam, char *array)
{
	int	cont;

	cont = 0;
	if (n == -2147483648)
	{
		array[10] = '8';
		n /= 10;
		tam--;
	}
	if (n < 0)
	{
		array[0] = '-';
		n *= -1;
		cont++;
	}
	while (cont < tam)
	{
		array[tam - 1] = (n % 10) + '0';
		n /= 10;
		tam--;
	}	
	return (array);
}
