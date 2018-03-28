/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:31:40 by msicot            #+#    #+#             */
/*   Updated: 2018/03/28 14:58:50 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/libftprintf.h"
# include "../libft/inc/get_next_line.h"
# define MAP info->map

typedef struct s_fill
{
	int		lecture;
	int		width;
	int		height;
	int		player;
	char	**map;
	char	**piece;
	int		p_height;
	int		p_width;
	char	*test;
}				t_fill;
char			**ft_board(int h, int w);
void			ft_clear_tab(char ***tab, int h);
void			ft_piece(t_fill *info, char *buff, int i);
#endif
