/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:31:40 by msicot            #+#    #+#             */
/*   Updated: 2018/03/27 17:33:25 by msicot           ###   ########.fr       */
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

typedef struct s_fill
{
	int		lecture;
	int		width;
	int		heigth;
	int		player;
	char	**map;
	char	*test;
}				t_fill;
char			**ft_board(t_fill *info);
#endif
