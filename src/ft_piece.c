/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:36:06 by msicot            #+#    #+#             */
/*   Updated: 2018/03/28 15:04:57 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_piece(t_fill *info, char *buff, int i)
{
	char	**tab;

	if (ft_strstr(buff, "Piece") != NULL)
	{
		tab = ft_strsplit(buff, ' ');
		info->p_height = ft_atoi(tab[1]);
		info->p_width = ft_atoi(tab[2]);
		ft_clear_tab(&tab, 3);
		if (info->piece == NULL)
			info->piece = ft_board(info->p_height, info->p_width);
	}
	else if (i >= 0)
	{
		info->piece[i] = ft_strcpy(info->piece[i], buff);
	}
}
