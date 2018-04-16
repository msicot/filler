/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 09:38:20 by msicot            #+#    #+#             */
/*   Updated: 2018/04/16 12:20:43 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_map(t_fill *info, char *buff)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = MAP;
	if ((int)ft_strlen(buff) != W_MAP)
		return (0);
	MAP = ft_strjoin(MAP, buff);
	ft_strdel(&tmp);
	while (buff[i])
	{
		if (buff[i] != '.' && buff[i] != 'X' && buff[i] != 'O')
			return (0);
		++i;
	}
	return (1);
}

void		ft_piece(t_fill *info, char *buff)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = PIECE;
	if (ft_strncmp(buff, "Piece", 5) == 0)
	{
		info->p_height = ft_atoi(&buff[5]);
		info->p_width = ft_atoi(&buff[5 + 1 + ft_int_len(info->p_height)]);
	}
	else
	{
		tmp = PIECE;
		PIECE = ft_strjoin(PIECE, buff);
		ft_strdel(&tmp);
		tmp = PIECE;
		PIECE = ft_strjoin(PIECE, "\n");
		ft_strdel(&tmp);
		++info->end;
	}
}

static int	ft_player(t_fill *info, char *buff)
{
	if (ft_strncmp(buff, "$$$ exec p1", 11) == 0)
	{
		PLAYER = 'O';
		OPPO = 'X';
		return (1);
	}
	else if (ft_strncmp(buff, "$$$ exec p2", 11) == 0)
	{
		PLAYER = 'X';
		OPPO = 'O';
		return (1);
	}
	return (0);
}

int			ft_check_ln(char *buff, t_fill *info)
{
	if (buff)
	{
		if (ft_player(info, buff) == 1)
			return (1);
		else if (ft_strncmp(buff, "Plateau", 7) == 0)
		{
			H_MAP = ft_atoi(&buff[7]);
			W_MAP = ft_atoi(&buff[7 + ft_int_len(H_MAP) + 1]);
		}
		else if (buff[0] >= '0' && buff[0] <= '9')
		{
			if (get_map(info, buff + 4) == 0)
				return (0);
		}
		else if (buff[0] == '.' || buff[0] == '*' ||
				ft_strncmp(buff, "Piece", 5) == 0)
			ft_piece(info, buff);
		return (1);
	}
	return (0);
}
