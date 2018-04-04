/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 09:38:20 by msicot            #+#    #+#             */
/*   Updated: 2018/04/04 16:14:07 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_map(t_fill *info, char *buff)
{
	char *tmp;

	tmp = MAP;
	if ((int)ft_strlen(buff) != X_MAP)
		return (1);
	MAP = ft_strjoin(MAP, buff);
	ft_strdel(&tmp);
	tmp = MAP;
	MAP = ft_strjoin(MAP, "\n");
	ft_strdel(&tmp);
	return (0);
}

void	ft_piece(t_fill *info, char *buff)
{
	char	*tmp;

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
	}
}

int		ft_check_ln(char *buff, t_fill *info)
{
	if (buff)
	{
		if (ft_strncmp(buff, "$$$ exec p1", 11) == 0)
		{
			PLAYER = 'X';
			OPPO = 'O';
		}
		else if (ft_strncmp(buff, "$$$ exec p2", 11) == 0)
		{
			PLAYER = 'O';
			OPPO = 'X';
		}
		else if (ft_strncmp(buff, "Plateau", 7) == 0)
		{
			Y_MAP = ft_atoi(&buff[7]);
			X_MAP = ft_atoi(&buff[7 + ft_int_len(Y_MAP) + 1]);
		}
		else if (buff[0] >= '0' && buff[0] <= '9')
		{
			ERROR = get_map(info, buff + 4);
		}
		else if (buff[0] == '.' || buff[0] == '*' || ft_strncmp(buff, "Piece", 5) == 0)
					ft_piece(info, buff);
		return (1);
	}
	return (0);
}
