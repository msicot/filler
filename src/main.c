/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:22:24 by msicot            #+#    #+#             */
/*   Updated: 2018/03/27 16:56:26 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*void	ft_read_un(t_fill *info)
{

	ft_printf("->TESSSTTTTT%s<-\n", instr);
}*/

void	ft_check_ln(int fd, char **tmp, t_fill *info)
{
	char *buff;
	 char	**tab;
	buff = *tmp;
	if	(ft_strncmp(buff, "$$$ exec p1", 11) == 0)
		info->player = 1;
	else if	(ft_strncmp(buff, "$$$ exec p2", 11) == 0)
		info->player = 2;
	else if (ft_strncmp(buff, "Plateau", 7) == 0)
	{
		tab = ft_strsplit(buff, ' ');
		info->width = ft_atoi(tab[1]);
		info->heigth = ft_atoi(tab[2]);
	}
	info.map = ft_board(info);
	int k;
	k = fd;
/*	else
	{
		tab = ft_strsplit(buff, ' ');
		int k = 0;
		while (tab[k] != '\0')
		{
			ft_putstr_fd(tab[k++], fd);
			ft_putchar_fd('\n', fd); 
		}
}
*/
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
	while(get_next_line(0, &instr) >= 1)
	{
		ft_check_ln(fd, &instr, &info);
	}
	info.test = instr;

			ft_putstr_fd(instr, fd);
i = 11;
	ft_putnbr_fd(info.width, fd);
	ft_strdel(&instr);
	return (0);
}
