/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:28:53 by msicot            #+#    #+#             */
/*   Updated: 2018/04/13 14:53:58 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_try_set(t_fill *info, int pos, int pos_p)
{
	int y;
	int x;

	y = pos_p / W_P;
	x = pos_p % W_P;
	if ((pos / W_MAP) + y < H_MAP)
	{
		if ((pos % W_MAP) + x < W_MAP)
		{
			if ((P_TAB[pos / W_MAP + y][pos % W_MAP + x] == -1 && SET == 0) ||
					(P_TAB[pos / W_MAP + y][pos % W_MAP + x] != -1 &&
					O_TAB[pos / W_MAP + y][pos % W_MAP + x] != -1))
			{
				if (P_TAB[pos / W_MAP + y][pos % W_MAP + x] == -1)
					SET = 1;
				return (0);
			}
		}
	}
	return (-1);
}

int			ft_check_place(t_fill *info, int pos)
{
	int pos_p;

	info->set = false;
	pos_p = 0;
	if (pos < (H_MAP * W_MAP))
	{
		while (pos_p < (W_P * H_P))
		{
			if (P2[pos_p / W_P][pos_p % W_P] == '*')
			{
				if (ft_try_set(info, pos, pos_p) == -1)
					return (-1);
			}
			++pos_p;
			if (pos_p == (W_P * H_P) && SET == 1)
				return (pos);
		}
	}
	return (-1);
}
