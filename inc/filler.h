/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msicot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:31:40 by msicot            #+#    #+#             */
/*   Updated: 2018/03/26 14:56:47 by msicot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/inc/libft.h"
# include "../libft/inc/libftprintf.h"
# include "../libft/inc/get_next_line.h"
#define	BUFF_S 32

typedef struct s_fill
{
	int		width;
	int		heigth;
	char	**map;
	char	*test;
}				t_fill;
#endif
