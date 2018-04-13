/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:29:12 by msicot            #+#    #+#             */
/*   Updated: 2018/04/13 16:09:59 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_score_team(t_fill *info)
{
	int pos;

	pos = 0;
	while (pos < (W_MAP * H_MAP))
	{
		if (MAP[pos] == OPPO)
			++info->cur_op;
		if (MAP[pos] == PLAYER)
			++info->my_score;
		++pos;
	}
}

static void	score_distri(t_fill *info, int score)
{
	if (score >= info->score)
	{
		if ((score == info->score && PLAYER == 'O') || score > info->score)
		{
			info->score = score;
			info->curr_posf = info->curr_pos;
		}
		else if (PLAYER == 'X' && score > info->score)
		{
			info->score = score;
			info->curr_posf = info->curr_pos;
		}
	}
}

static int	ft_scoring2(t_fill *info, int **tab)
{
	int y;
	int x;
	int score;

	y = 0;
	score = 0;
	while (y < H_MAP)
	{
		x = 0;
		while (x < W_MAP)
		{
			score += (tab[y][x] > 0) ? 1 : 0;
			++x;
		}
		++y;
	}
	score_distri(info, score);
	return (score);
}

int			ft_scoring(t_fill *info, int **tab)
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
			tab[y][x] = b - a;
			++x;
		}
		++y;
	}
	return (ft_scoring2(info, tab));
}
