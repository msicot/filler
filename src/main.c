/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:22:24 by msicot            #+#    #+#             */
/*   Updated: 2018/04/09 17:27:07 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_read_vm(t_fill *info)
{
	int i;
	char *buff;

	int k;
	k = info->fd;
//	line = 0;
	i = 0;
	while (1)
	{
		get_next_line(0, &buff);
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
int main()
{
	t_fill	info;
	info.fd = open("/Users/msicot/Documents/mas_github/filler/try.txt", O_CREAT | O_APPEND | O_RDWR, 777);
	info.player = 0;
	info.height = 0;
	info.width = 0;
	info.end = 0;
	info.piece_set = false;
	info.map = ft_strnew(0);
	info.piece = ft_strnew(0);
		
	while (1)
	{
		if (ft_read_vm(&info) == 0)
			ft_printf("8 2\n");
		break;
	}
	ft_putstr_fd(info.map, 2);
	//	ft_int_tab(&info);
	return (0);
}
