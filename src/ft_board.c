/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:54:55 by msicot            #+#    #+#             */
/*   Updated: 2018/03/27 17:10:16 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**ft_board(t_fill *info)
{
	int	i;
	char	**tab;

	i = 0;
	if (!(tab = (char**)malloc(sizeof(char *) * (info->heigth + 1))))
		return (NULL);
	while (i <= info.heigth)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * (info->width + 1))))
			return (NULL);
		ft_bzero(&tab[i++], info->width + 1);
	}	
	return (tab);
}
