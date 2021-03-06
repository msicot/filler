/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 09:36:47 by msicot            #+#    #+#             */
/*   Updated: 2018/04/10 18:38:32 by msicot           ###   ########.fr       */
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

static void	ft_bomba(t_fill *info, int target, int ***tab2)
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

void		ft_int_tab(t_fill *info, int ***tab2, char c)
{
	int	i;
	int	**tab;

	tab = *tab2;
	i = 0;
	tab = (int **)malloc(sizeof(int *) * info->height);
	while (i < info->height)
		tab[i++] = (int*)malloc(sizeof(int) * info->width);
	ft_set_tab(info, &tab, c);
	ft_print_itab(info, tab);
}
