/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:54:55 by msicot            #+#    #+#             */
/*   Updated: 2018/04/13 10:21:14 by msicot           ###   ########.fr       */
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

	while (y < H_MAP)
	{
		x = 0;
		while (x < W_MAP)
		{
			if (tab[y][x] < 10 && tab[y][x] >=0)
			{
				ft_putstr_fd(" ", info->fd);
			}
			ft_putnbr_fd(tab[y][x], info->fd);
			if (tab[y][x] < 0)
			{
				ft_putstr_fd(" ", info->fd);
			}
			else if (tab[y][x] < 10 && tab[y][x] >=0)
			{
				ft_putstr_fd(" ", info->fd);
			}
			else 
				ft_putstr_fd(" ", info->fd);
			++x;
		}
		ft_putstr_fd("\n", info->fd);
		++y;
	}
}
