/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:44:39 by msicot            #+#    #+#             */
/*   Updated: 2018/04/13 12:03:06 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
static void		ft_replace(t_fill *info, int ***tab2)
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
			if(tab[y][x] < 0)
			tab[y][x] = 0;
			++x;
		}
		++y;
	}
}
// remet des 0 dans la map tab_try
static void		ft_replace2(t_fill *info, int ***tab2)
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
			if(tab[y][x] > -1)
			tab[y][x] = 0;
			++x;
		}
		++y;
	}
}

static int		ft_scoring(t_fill *info, int **tab)
{
	int x;
	int y;
	int	score;
	int	a;
	int b;

	a = 0;
	b = 0;
	score = 0;
	y = 0;
	while (y < H_MAP)
	{
		x = 0;
		while (x < W_MAP)
		{
			a = tab[y][x];
			b = (O_TAB[y][x] == -1) ? 0 : O_TAB[y][x];
			tab [y][x]= b - a;
			++x;
		}
		++y;
	}
	y = 0;
	while (y < H_MAP)
	{
		x = 0;
		while (x < W_MAP)
		{
			score += (tab[y][x] > 0) ? 1: 0;
			++x;
		}
		++y;
	}
	return (score);
}

void	ft_fill_tab(int ***tab2, int pos, t_fill *info)
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
			break;
	}
}

int ft_algo(t_fill *info)
{
	int pos;
	int	**tab_try;
	int	posf;
	int score;
	posf = -1;
	pos = 0;
	ft_prepa_algo(info);
	while (pos < (W_MAP * H_MAP))
	{
		if (ft_check_place(info, pos) >= 0)
		{
			if (info->cur_op == info->nb_op && info->my_score > info->nb_op)
					return (-1);
			if (info->cur_op == info->nb_op)
				return (pos);
			tab_try = ft_tab(info, PLAYER); 
			ft_fill_tab(&tab_try, pos, info);
			ft_replace2(info, &tab_try);
			// relancer la bombe pour recalculer le score
			ft_bomba(info, -1, &tab_try);
			ft_replace(info, &tab_try);
/*		ft_replace(info, &O_TAB);
		*///	ft_print_itab(info, tab_try);
			score = ft_scoring(info, tab_try);
			ft_putstr_fd("Score global - ", info->fd);
			ft_putstr_fd("ME =", info->fd);
			ft_putnbr_fd(info->my_score, info->fd);
			ft_putstr_fd(" ", info->fd);
			ft_putstr_fd("OP =", info->fd);
			ft_putnbr_fd(info->cur_op, info->fd);
			ft_putstr_fd("\n\n", info->fd);
			if (score >= info->score)
			{
			//	ft_putstr_fd("Score retenu\n\n", info->fd);
				if ((score == info->score && PLAYER == 'O') || score > info->score)
				{
					info->score = score;
					posf = pos;
				}
				else if (PLAYER == 'X' && score > info->score)
				{
					info->score = score;
					posf = pos;
				}
			}
			ft_clear_itab(&tab_try, H_MAP);
		//	posf = pos;
		}
		++pos;
		if (pos == W_MAP * H_MAP && posf != -1)
			return (posf);
	}
	return (-1);
}
