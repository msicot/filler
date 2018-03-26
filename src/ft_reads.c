/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reads.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:35:45 by msicot            #+#    #+#             */
/*   Updated: 2018/03/26 12:28:10 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*ft_clean(char **cmd)
{
	char 	*tmp;
	char	*new;
	char	*ncmd;

	if (cmd == NULL)
		return (NULL);
	tmp = *cmd;
	if (!(new = ft_strnew(BUFF_S)))
		return (NULL);
	if (!(ncmd = ft_strjoin(tmp, new)))
		return (NULL);
	ft_strdel(&tmp);
	ft_strdel(&new);
	return (ncmd);
}

char 	*ft_reads(void)
{
	char	c;
	char	*buff;
	int		i;

	i = 0;
	ft_printf("minishell $>");
	buff = ft_strnew(BUFF_S + 1);
	while (read(0, &c, 1) > 0)
	{
		if (c == '\n')
			break;
		buff[i++] = c;
		if (i >= BUFF_S)
		{
			if (!(buff = ft_clean(&buff)))
				return (NULL);
			i = 0;
		}
	}
	return (buff);
}

