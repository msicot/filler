/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:22:24 by msicot            #+#    #+#             */
/*   Updated: 2018/03/26 15:32:15 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_read_un(t_fill *info)
{
	char	*instr;

	instr = NULL;
	get_next_line(0, &instr);
	info->test = instr;
	ft_printf("->TESSSTTTTT%s<-\n", instr);
}

int main()
{
	t_fill	info;

		ft_printf("14 12\n");
	return (0);
}

