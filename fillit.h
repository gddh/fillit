/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:16:47 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/09 17:35:07 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

# define EMPTY 60
# define EMPTY_VEC "0000"
# define START_SIZE 2

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
