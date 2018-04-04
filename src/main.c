/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:22:24 by msicot            #+#    #+#             */
/*   Updated: 2018/04/04 16:14:06 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_read_vm(t_fill *info)
{
	char *buff;

	while (1)
	{
	 	get_next_line(0, &buff);
		if (ft_check_ln(buff, info) == 0)
		{
			ft_strdel(&buff);
			break;
		}
		ft_putstr_fd(buff, info->fd);ft_putstr_fd("\n", info->fd);
		if (buff != NULL)
		{
			ft_strdel(&buff);
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
	info.piece_set = false;
	info.map = ft_strnew(0);
	info.piece = ft_strnew(0);
	while (1)
	{
		if (ft_read_vm(&info) == 0)
		{
			break;
		}
	}
	ft_putstr_fd(info.map, info.fd);
	ft_printf("8 2\n");
	//	ft_int_tab(&info);
	return (0);
}
