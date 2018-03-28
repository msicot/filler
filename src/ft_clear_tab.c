/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:26:34 by msicot            #+#    #+#             */
/*   Updated: 2018/03/28 14:58:45 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_clear_tab(char	***tab, int h)
{
	char	**tmp;
	int		i;

	if (tab == NULL)
			return ;
	tmp = *tab;
	i = 0;
	while (i < h)
	{
		ft_strdel(&tmp[i]);
		++i;
	}
	free(tmp);	
}
