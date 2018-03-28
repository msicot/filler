/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:22:24 by msicot            #+#    #+#             */
/*   Updated: 2018/03/28 15:12:44 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*void	ft_read_un(t_fill *info)
{

	ft_printf("->TESSSTTTTT%s<-\n", instr);
}*/

void	ft_check_ln(int fd, char *tmp, t_fill *info, int i)
{
	char	*buff;
	char	**tab;

	buff = tmp;
	if	(ft_strstr(buff, "$$$ exec p1") != NULL)
		info->player = 1;
	else if	(ft_strstr(buff, "$$$ exec p2") != NULL)
		info->player = 2;
	else if (ft_strstr(buff, "Plateau") != NULL)
	{
		tab = ft_strsplit(buff, ' ');
		info->height = ft_atoi(tab[1]);
		info->width = ft_atoi(tab[2]);
		ft_putnbr_fd(info->height, fd);
		ft_putnbr_fd(info->width, fd);
		ft_putstr_fd("\n", fd);
//		info->map = ft_board(info->heigth, info->width);
		ft_clear_tab(&tab, 3);
	}	
	else if (ft_strstr(buff, "    ") != NULL)
		return ;
	else if (i <= info->height)
	{
		MAP[i] = ft_strcpy(MAP[i], &buff[4]);
		ft_putstr_fd(MAP[i], fd);
		ft_putstr_fd("\n", fd);
		return;
	}
	else if (i > info->height)
	{
		i = i - (info->height + 1);
		ft_putnbr_fd(i, fd);
		ft_putstr_fd(buff, fd);
		ft_putstr_fd("\n", fd);
		ft_piece(info, buff, i);
	}
}

int main()
{
	t_fill	info;
	int		fd;
	char	*instr;
	size_t i = 0;
	fd = open("/Users/msicot/Documents/mas_github/filler/try.txt", O_CREAT | O_APPEND | O_RDWR, 777);
	instr = NULL;
	info.player = 0;
	info.height = 0;
	info.width = 0;
	info.map = NULL;
	info.piece = NULL;
	while(get_next_line(0, &instr) >= 1)
	{
		ft_putnbr_fd(i, fd);
		ft_check_ln(fd, instr, &info, i);
		if (info.map == NULL && info.width != 0 && info.height != 0)
		{
			info.map = ft_board(info.height, info.width);
			i = 0;
			continue ;
		}
		++i;
	}
	i = 11;
	ft_strdel(&instr);
	ft_clear_tab(&info.map, info.height);
	ft_clear_tab(&info.piece, info.p_height);

//	ft_printf("14 12\n");
	return (0);
}
