/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:44:36 by mortiz-d          #+#    #+#             */
/*   Updated: 2021/11/11 19:43:42 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	alznum(int n, int fd);

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb <= 2147483647 && nb >= 0)
		alznum(nb, fd);
	else if (nb < 0 && nb > -2147483647)
	{
		if (nb == -2147483648)
		{
			nb = nb / 10;
			nb = nb * -1;
			ft_putchar_fd('-', fd);
			alznum(nb, fd);
			ft_putchar_fd('8', fd);
		}
		else
		{
			nb = nb * -1;
			ft_putchar_fd('-', fd);
			alznum(nb, fd);
		}		
	}
}

void	alznum(int n, int fd)
{	
	int	x;

	x = n % 10;
	if (n / 10 != 0)
		alznum((n / 10), fd);
	ft_putchar_fd(x + '0', fd);
}
