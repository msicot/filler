/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:54:55 by msicot            #+#    #+#             */
/*   Updated: 2018/03/28 13:26:26 by msicot           ###   ########.fr       */
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
		tab[i][w] = '\0';
		++i;
	}	
	return (tab);
}
