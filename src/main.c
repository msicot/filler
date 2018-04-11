/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:22:24 by msicot            #+#    #+#             */
/*   Updated: 2018/04/11 18:00:44 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_read_vm(t_fill *info, char *buff)
{
	while (1)
	{
		get_next_line(0, &buff);
	/*	ft_putstr_fd("buff= ", 2);
		ft_putstr_fd(buff, 2);
	ft_putstr_fd("\n", 2);*/
		if (ft_check_ln(buff, info) == 0)
		{
			ft_strdel(&buff);
			break;
		}
		ft_strdel(&buff);
		if (info->end != 0 && info->end == info->p_height)
		{
			return (0);
		}
	}
	return (0);
}

static void	ft_clear_info(t_fill *info)
{
	ft_strdel(&MAP);
	ft_strdel(&PIECE);
	ft_clear_tab(&P2, H_P);
	ft_clear_itab(&P_TAB, H_P);
	ft_clear_itab(&O_TAB, H_P);
}

static void set_var(t_fill *info)
{

	info->fd = open("/Users/msicot/Documents/mas_github/filler/try.txt", O_CREAT | O_APPEND | O_RDWR, 777);
//	info->player = 0;
	info->pos_f = -1;
	info->height = 0;
	info->width = 0;
	info->end = 0;
	info->piece_set = false;
	info->map = ft_strnew(0);
	info->piece = ft_strnew(0);
}

int 		main()
{
	t_fill	info;
	char *buff;

	buff = 0;		
	set_var(&info);
	while (1)
	{
		if (ft_read_vm(&info, buff) == -1)
			break ; 
		info.pos_f = ft_algo(&info);
		if (info.pos_f >= 0)
			ft_printf("%d %d\n", info.pos_f / info.width, info.pos_f % info.width);
		ft_putstr_fd("pos_f= ", 2);
		ft_putnbr_fd(info.pos_f, 2);
		ft_putstr_fd("\n", 2);
		if (info.pos_f == -1)
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
