/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepa_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 08:39:08 by msicot            #+#    #+#             */
/*   Updated: 2018/04/13 16:25:51 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_expand(t_fill *info, int x, int y, int ***tab2)
{
	int target;
	int	**tab;

	tab = *tab2;
	target = info->target;
	if (y > 0 && tab[y - 1][x] == 0)
		tab[y - 1][x] = (target == -1) ? 1 : target + 1;
	if (y < H_MAP - 1 && tab[y + 1][x] == 0)
		tab[y + 1][x] = (target == -1) ? 1 : target + 1;
	if (x > 0 && tab[y][x - 1] == 0)
		tab[y][x - 1] = (target == -1) ? 1 : target + 1;
	if (x < W_MAP - 1 && tab[y][x + 1] == 0)
		tab[y][x + 1] = (target == -1) ? 1 : target + 1;
}

void		ft_bomba(t_fill *info, int target, int ***tab2)
{
	int	zero;
	int	**tab;
	int	x;
	int	y;

	y = 0;
	info->target = target;
	tab = *tab2;
	zero = 0;
	while (y < H_MAP)
	{
		x = 0;
		while (x < W_MAP)
		{
			if (tab[y][x] == 0)
				zero = 1;
			else if (tab[y][x] == target)
				ft_expand(info, x, y, &tab);
			++x;
		}
		++y;
	}
	target = (target == -1) ? 1 : target + 1;
	if (zero == 1)
		ft_bomba(info, target, &tab);
}

static void	ft_set_tab(t_fill *info, int ***tab, char c)
{
	int		pos;
	int		x;
	int		y;
	char	a;

	a = (c == 'X') ? 'O' : 'X';
	pos = 0;
	y = 0;
	while (y < H_MAP && ERROR == 0)
	{
		x = 0;
		while (x < W_MAP && ERROR == 0)
		{
			if (MAP[pos] == c)
				(*tab)[y][x] = -1;
			else if (MAP[pos] == '.' || MAP[pos] == a)
				(*tab)[y][x] = 0;
			else
				ERROR = -2;
			++pos;
			++x;
		}
		++y;
	}
	ft_bomba(info, -1, tab);
}

int			**ft_tab(t_fill *info, char c)
{
	int	i;
	int	**tab;

	i = 0;
	tab = (int **)malloc(sizeof(int *) * info->height);
	while (i < info->height)
		tab[i++] = (int*)malloc(sizeof(int) * info->width);
	ft_set_tab(info, &tab, c);
	return (tab);
}

void		ft_prepa_algo(t_fill *info)
{
	int pos;

	info->curr_posf = -1;
	info->curr_pos = 0;
	if (PLAYER == 'X')
	{
		P_TAB = ft_tab(info, 'X');
		O_TAB = ft_tab(info, 'O');
	}
	else if (PLAYER == 'O')
	{
		P_TAB = ft_tab(info, 'O');
		O_TAB = ft_tab(info, 'X');
	}
	P2 = ft_strsplit(info->piece, '\n');
	pos = 0;
	ft_score_team(info);
}
