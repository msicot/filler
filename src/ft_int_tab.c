/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 09:36:47 by msicot            #+#    #+#             */
/*   Updated: 2018/04/09 17:27:06 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*void	ft_set_tab(t_fill *info, int ***tab)
{
	int	x;
	int	y;
	int **t;

	t = *tab;
	y = 0;
	// player o
	ft_putstr_fd(MAP[0], info->fd);
	ft_putstr_fd("<--- testing 1st line\n", info->fd);
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (MAP[y][x] == 'O' || MAP[y][x] == 'X')
				t[y][x] = 1;
			else if (MAP[y][x] == '.')
				t[y][x] = 0;
			else
				t[y][x] = -9;
			++x;
		}
		++y;
	}
//	ft_print_itab(info, t);
}

void	ft_bomb(t_fill *info, int ***tab)
{
	int	**tmp;
	int	x;
	int	y;

	tmp = *tab;
	y = 0;
}
*/
void	ft_int_tab(t_fill *info)
{
	int	i;

	i = 0;
	info->x_tab = (int **)malloc(sizeof(int *) * info->height);
	while (i < info->height)
		info->x_tab[i++] = (int*)malloc(sizeof(int) * info->width);

	info->o_tab = (int **)malloc(sizeof(int *) * info->height);
	i = 0;
	while (i < info->height)
		info->o_tab[i++] = (int*)malloc(sizeof(int) * info->width);

//	ft_set_tab(info, &info->o_tab);
//	ft_set_tab(info, &info->x_tab);
	//ft_bombe(info, &info->o_tab);
}
