/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:18:32 by msicot            #+#    #+#             */
/*   Updated: 2017/11/15 09:30:14 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = n * -1;
		if (n == -2147483648)
		{
			nb = 2147483648;
		}
	}
	else
	{
		nb = n;
	}
	if (nb / 10 > 0)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	ft_putchar_fd((nb % 10) + 48, fd);
}
