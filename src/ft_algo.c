/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:44:39 by msicot            #+#    #+#             */
/*   Updated: 2018/04/11 18:02:12 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
		if (P2[y][x] == 42)
		{
			(*tab2)[pos / W_MAP + y][pos % W_MAP + x] = ((*tab2)[pos / W_MAP + y][pos % W_MAP + x] == -1) ? -1 : -2; 
		}
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

	posf = -1;
	pos = 0;
	ft_prepa_algo(info);
	while (pos < (W_MAP * H_MAP))
	{
		if ((info->pos_f = ft_check_place(info, pos)) >= 0)
		{
			tab_try = ft_tab(info, PLAYER); 
			ft_fill_tab(&tab_try, pos, info);
	//		ft_putstr_fd("found\n", 2);
			ft_print_itab(info, tab_try);
	//		ft_printf("%d %d", pos % W_MAP, pos / W_MAP);
			ft_clear_itab(&tab_try, H_P);
			posf = pos;
			//return (pos);
//			/Calcul du score, enregistrement, et on continue.
		}
		++pos;
		if (pos == W_MAP * H_MAP && posf != -1)
			return (posf);
	}
	return (-1);
}
