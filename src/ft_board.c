/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:54:55 by msicot            #+#    #+#             */
/*   Updated: 2018/04/11 09:19:47 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**ft_board(int h, int w)
{
	int	i;
	char	**tab;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * h + 1)))
		return (NULL);
	tab[h] = 0;
	while (i <= h)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * w + 1)))
			return (NULL);
		ft_bzero(tab[i], w);
		tab[i][w] = '\0';
		++i;
	}	
	return (tab);
}

void	ft_print_itab(t_fill *info, int **tab)
{
	int x = 0;
	int y = 0;

	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (tab[y][x] < 10 && tab[y][x] >=0)
			{
				ft_putstr_fd(" ", 2);
			}
			ft_putnbr_fd(tab[y][x], 2);
			if (tab[y][x] < 0)
			{
				ft_putstr_fd(" ", 2);
			}
			else if (tab[y][x] < 10 && tab[y][x] >=0)
			{
				ft_putstr_fd(" ", 2);
			}
			else 
				ft_putstr_fd(" ", 2);
			++x;
		}
		ft_putstr_fd("\n", 2);
		++y;
	}
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("\n", 2);
}
