/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:34:13 by delin             #+#    #+#             */
/*   Updated: 2018/05/10 21:01:35 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** if any errors occur, we should print `error` to stdout and exit the program
*/

void			fillit_exit(void)
{
	ft_putendl("error");
	exit(1);
}

/*
** helper function for parsing input, mutate arr by subtracting 1 from each elem
*/

void			sub_one(void *elem, size_t i, int *stop)
{
	(void)stop;
	(void)i;
	*(int*)elem -= 1;
}

/*
** helper function for parsing input, stops and returns if a 0 is found
*/

static void			*zero_found(void *final, void *elem, size_t i, int *stop)
{
	(void)final;
	(void)i;
	return ((*stop = *(int*)elem == 0 ? 1 : 0));
}

/*
** print given row to stdout, once found
*/

void				draw(char **board, int n)
{
	int y;
	int x;

	y = 0;
	while (y < n)
	{
		x = 0;
		while (x < n)
		{
			ft_putchar(board[y][x]);
			x = x + 1;
		}
		ft_putchar('\n');
		y = y + 1;
	}
}

/*
** Returns a 2D char array filled with `.` that represents a board of size n x n 
*/

char		**init_board(int n)
{
	int		i;
	int		j;
	char	**board;

	if (!(board = (char **)ft_memmalloc(sizeof(char *) * n)))
		fillit_exit();
	i = -1;
	while (++i < n)
	{
		if (!(board[i] = (char *)ft_memmalloc(sizeof(char) * n)))
			fillit_exit();
		j = -1;
		while (++j < n)
			board[i][j] = '.';
	}
	return (board);
}
