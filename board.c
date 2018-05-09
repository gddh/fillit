/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:34:13 by delin             #+#    #+#             */
/*   Updated: 2018/05/09 11:41:37 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "board.h"

/*
** given a 2D board and the size, draw will
** output the board to stdout using ft_putchar
*/

void		draw(char **board, int n)
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
** A helper function to fill a given board with '.'
*/

static void	fill_board(char **board, int n)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		if (!(board[i] = (char *)malloc(sizeof(char) * n)))
		{
			ft_putstr_fd("Insufficient memory for malloc.\n", 2);
			exit(1);
		}
		j = 0;
		while (j < n)
		{
			board[i][j] = '.';
			j = j + 1;
		}
		i = i + 1;
	}
}

/*
** Frees the board that we draw
*/

void		free_board(char **board, int n)
{
	int i = 0;

	while (i < n)
	{
		free(board[i]);
		i = i + 1;
	}
}

/*
** Returns a 2D char array that represents a board of size nxn.
** The initial board is filled with `.`
*/

char		**init_board(int n)
{
	char **board;

	board = (char **)malloc(sizeof(char *) * n);
	if (!board)
	{
		ft_putstr_fd("Insufficient memory for malloc.\n", 2);
		exit(1);
	}
	fill_board(board, n);
	return (board);
}
