/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:31:40 by msicot            #+#    #+#             */
/*   Updated: 2018/04/13 15:11:04 by msicot           ###   ########.fr       */
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
# define W_MAP info->width
# define H_MAP info->height
# define PLAYER info->player
# define OPPO info->opponent
# define ERROR info->error
# define PIECE info->piece
# define P_TAB info->p_tab
# define O_TAB info->o_tab
# define P2 info->piece2
# define H_P info->p_height
# define W_P info->p_width
# define SET info->set
# define POS_PL info->p_tab[pos / W_MAP][pos % W_MAP]
# define POS_O info->o_tab[pos / W_MAP][pos % W_MAP]
typedef struct s_fill
{
	int		lecture;
	int		fd;
	int		width;
	int		height;
//	int		player;
	char	*map;
	char	*piece;
	char	**piece2;
	bool	piece_set;
	int		p_height;
	int		p_width;
	char	*test;
	int		**p_tab;
	int		**o_tab;
	int		p;
	char	player;
	char	opponent;
	int		error;
	int		end;
	int		target;
	int		score;
	int		pos_f;
	int		nb_op;
	int		cur_op;
	int		my_score;
	bool	set;
	int		curr_posf;
	int		curr_pos;
}				t_fill;

int				ft_int_len(int n);
int				ft_check_ln(char *buff, t_fill *info);
char			**ft_board(int h, int w);
void			ft_clear_tab(char ***tab, int h);
void			ft_clear_itab(int ***tab, int h);
void			ft_piece(t_fill *info, char *buff);
int				**ft_tab(t_fill *info, char c);
void			ft_print_itab(t_fill *info, int **tab);
void			ft_prepa_algo(t_fill *info);
int				ft_algo(t_fill *info);
void			ft_bomba(t_fill *info, int target, int ***tab2);
int				ft_check_place(t_fill *info, int pos);
void			ft_score_team(t_fill *info);
int				ft_scoring(t_fill *info, int **tab);
//void			ft_crop(t_fill *info);
#endif
