/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:31:40 by msicot            #+#    #+#             */
/*   Updated: 2018/04/09 16:37:39 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <sys/types.h>
# include <sys/uio.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/libftprintf.h"
# include "../libft/inc/get_next_line.h"
# define MAP info->map
# define X_MAP info->width
# define Y_MAP info->height
# define PLAYER info->player
# define OPPO info->opponent
# define ERROR info->error
# define PIECE info->piece

typedef struct s_fill
{
	int		lecture;
	int		fd;
	int		width;
	int		height;
//	int		player;
	char	*map;
	char	*piece;
	bool	piece_set;
	int		p_height;
	int		p_width;
	char	*test;
	int		**x_tab;
	int		**o_tab;
	int		p;
	char	player;
	char	opponent;
	int		error;
	int		end;
}				t_fill;

int				ft_int_len(int n);
int				ft_check_ln(char *buff, t_fill *info);
char			**ft_board(int h, int w);
void			ft_clear_tab(char ***tab, int h);
void			ft_piece(t_fill *info, char *buff);
void			ft_int_tab(t_fill *info);
void			ft_print_itab(t_fill *info, int **tab);
//void			ft_crop(t_fill *info);
#endif
