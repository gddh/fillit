/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:06:37 by delin             #+#    #+#             */
/*   Updated: 2018/05/09 11:41:33 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "queue.h"

/*
** Checks if the tetrimino can be placed at the x and y such that
** the x and y match the top left corner of the tetrimino.
** Note the tetrimino's top left corner can be empty 
*/

int		is_safe(char **board, t_tetrimino tetri, int N, int x, int y)
{
	int i;

	i = 0;
    while(i < 4)
    {
        x_i = tetri->x[i];
        y_i = tetri->y[i];
        if (x + x_i < N && y + y_i < N)    
        {
            if (board[y + y_i][x + x_i] != '.')
                return (0);
        }
		i = i + 1;
    }
    return (1);
}

/*
** Draws the tetrimino on the board such that the x and y 
** match the top left of the board. The function will draw
** using the tetrimino's id. 
** NOTE: if x and y are a struct, we shorten this function
** 			and remove_tetri with a helper...
*/

void		draw_tetrimino(char **board, t_tetrimino tetri, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		x_i = tetri->x[i];
		y_i = tetri->y[i];
		board[y + y_i][x + x_i] = tetri->id;
		i = i + 1;
	}
}

/*
** Removes the tetrimino on the board such that the x and y 
** match the top left of the board. The tetrimino block 
** positions will be replaced with '.'s
*/

void	remove_tetrimino(char **board, t_tetrimino tetri, int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		x_i = tetri->x[i];
		y_i = tetri->y[i];
		board[y + y_i][x + x_i] = '.';
		i = i + 1;
	}
}

/*
 * Backtracking algorithm to fill the board. Takes in a board
 * of size n x n, a tetrimino deque, and board side length.
 * If the deque is empty, then all tetriminos have been placed
 * on the board. If no solution has been found, then return 0.
 */

int    backtrack(char **board,t_queue *dq, int n)
{
	int x;
	int y;
    t_tetrimino *cur_tetri;

	if (is_empty(dq))
        return (1);     
     y = 0;
     while (y < n)
     {
         x = 0;
         while (x < n)
         {
             if (is_safe(board, peek(dq), x, y, n))
             {
                 cur_tetri = dequeue(&dq);
                 place_tetrimino(board, cur_tetri, x, y);
                 if (backtrack(board, dq, n))
                     return (1);
                remove_tetrimino(board, cur_tetri, x, y);
                enqueue_front(&dq, cur_tetri);
             }
             x = x + 1;
         }
         y = y + 1;
     }
     return (0);
}

void	fillit(t_board *minos)
{
	t_queue	*dq;
	int 	board_size;
	char	**board;
	int		sol_found;


	dq = init_queue();
	board_size = START_SIZE - 1;
	/*
	 * Not sure if this is proper way to go to next tetrimino 
	 * I'm trying to put all of the tetriminos into the deque
	*/
	while (minos->count > 0)
	{
		enqueue_back(&dq, minos->pieces);
		minos->pieces + sizeof(t_tetrimino);
		minos->count--;
	}
	sol_found = 0;
	while (!sol_found)
	{
		if (!sol_found)
		{
			board_size = board_size + 1;
			board = init_board(board_size);
		}
		sol_found = backtrack(board, dq, board_size);
		if (sol_found)
			draw(board, board_size);
		free_board(board, board_size);
	}
	destroy_q(dq);
}
