/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:16:47 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/12 16:33:54 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "../libft/libft.h"

# define EMPTY 60
# define EMPTY_VEC "0000"
# define START_SIZE 2

typedef struct		s_coords
{
	int				x;
	int				y;
}					t_coords;

typedef struct		s_tetrimino
{
	int				x_vec[4];
	int				y_vec[4];
	char			id;
}					t_tetrimino;

typedef struct		s_board
{
	t_list			*pieces;
	unsigned int	count;
}					t_board;

/*
** fillit.c
*/

void				fillit(t_board *minos);

/*
** helpers.c
*/

void				sub_one(void *elem, size_t i, int *stop);
void				fillit_exit(void) __attribute__ ((noreturn));
void				*zero_found(void *final, void *elem, size_t i, int *stop);
void				draw(char **board, int n);
char				**init_board(int n);

/*
** parse.c
*/

t_board				*parse_board(char *path);
#endif