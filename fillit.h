/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:16:47 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/08 18:06:05 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H 

# include "libft/libft.h"

// empty needs to be something we can compare against easily
# define EMPTY 60
# define EMPTY_VEC "0000"

typedef struct		s_tetrimino
{
	int				x_vec[4];
	int				y_vec[4];
	char			id;
}					t_tetrimino;

typedef struct		s_board
{
	void			*pieces;
	unsigned int	count;
}					t_board;

#endif
