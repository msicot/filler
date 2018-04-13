/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:44:39 by msicot            #+#    #+#             */
/*   Updated: 2018/04/13 16:42:22 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	ft_replace(t_fill *info, int ***tab2)
{
	int x;
	int y;
	int	**tab;

	tab = *tab2;
	y = 0;
	while (y < H_MAP)
	{
		x = 0;
		while (x < W_MAP)
		{
			if (tab[y][x] < 0)
				tab[y][x] = 0;
			++x;
		}
		++y;
	}
}

static void	ft_replace2(t_fill *info, int ***tab2)
{
	int x;
	int y;
	int	**tab;

	tab = *tab2;
	y = 0;
	while (y < H_MAP)
	{
		x = 0;
		while (x < W_MAP)
		{
			if (tab[y][x] > -1)
				tab[y][x] = 0;
			++x;
		}
		++y;
	}
}

void		ft_fill_tab(int ***tab2, int pos, t_fill *info)
{
	int pos_p;
	int x;
	int y;

	pos_p = 0;
	while (pos_p < (W_P * H_P))
	{
		x = pos_p % W_P;
		y = pos_p / W_P;
		if (P2[y][x] == '*')
			(*tab2)[pos / W_MAP + y][pos % W_MAP + x] = -1;
		++pos_p;
		if (pos_p == W_P * H_P)
			break ;
	}
	ft_replace2(info, tab2);
	ft_bomba(info, -1, tab2);
	ft_replace(info, tab2);
}

/*
**if (info->cur_op == info->nb_op &&
**(info->my_score > info->nb_op + 10))
**return (-1);
*/

int			ft_algo(t_fill *info)
{
	int	**tab_try;
	int score;

	ft_prepa_algo(info);
	while (info->curr_pos < (W_MAP * H_MAP))
	{
		if (ft_check_place(info, info->curr_pos) >= 0)
		{
			if (info->cur_op == info->nb_op)
				return (info->curr_pos);
			tab_try = ft_tab(info, PLAYER);
			ft_fill_tab(&tab_try, info->curr_pos, info);
			score = ft_scoring(info, tab_try);
			ft_clear_itab(&tab_try, H_MAP);
		}
		++info->curr_pos;
		if (info->curr_pos == W_MAP * H_MAP && info->curr_posf != -1)
			return (info->curr_posf);
	}
	return (-1);
}
