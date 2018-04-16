/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:22:24 by msicot            #+#    #+#             */
/*   Updated: 2018/04/16 12:21:34 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_read_vm(t_fill *info, char *buff)
{
	while (1)
	{
		get_next_line(0, &buff);
		if (ft_check_ln(buff, info) == 0)
		{
			ft_printf("0 0\n");
			ft_strdel(&buff);
			return (0);
		}
		ft_strdel(&buff);
		if (info->end != 0 && info->end == info->p_height)
			break ;
	}
	return (1);
}

static void	ft_clear_info(t_fill *info)
{
	info->nb_op = info->cur_op;
	ft_strdel(&MAP);
	ft_strdel(&PIECE);
	ft_clear_tab(&P2, H_P);
	ft_clear_itab(&P_TAB, H_MAP);
	ft_clear_itab(&O_TAB, H_MAP);
}

static void	set_var(t_fill *info)
{
	info->pos_f = -1;
	info->height = 0;
	info->width = 0;
	info->score = -1;
	info->end = 0;
	info->piece_set = false;
	info->map = ft_strnew(0);
	info->piece = ft_strnew(0);
	info->my_score = 0;
	info->cur_op = 0;
}

int			main(void)
{
	t_fill	info;
	char	*buff;

	buff = 0;
	info.nb_op = -1;
	set_var(&info);
	while (1)
	{
		if (ft_read_vm(&info, buff) == 0)
			break ;
		info.pos_f = ft_algo(&info);
		if (info.pos_f >= 0)
			ft_printf("%d %d\n", info.pos_f / info.width,
					info.pos_f % info.width);
		else if (info.pos_f == -1)
		{
			ft_clear_info(&info);
			ft_printf("0 0\n");
			break ;
		}
		ft_clear_info(&info);
		set_var(&info);
	}
	return (0);
}
