/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:06:37 by delin             #+#    #+#             */
/*   Updated: 2018/05/10 23:54:21 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checks if the tetrimino can be placed at the x and y such that
** the x and y match the top left corner of the tetrimino.
** Note the tetrimino's top left corner can be empty 
*/

int		is_safe(char **board, t_tetrimino tetri, int N, t_coords coords)
{
	int		i;
	int		x_i;
	int		y_i;

	i = -1;
    while (++i < 4)
    {
        x_i = tetri->x_vec[i];
        y_i = tetri->y_vec[i];
        if (coords.x + x_i < N && coords.y + y_i < N)    
        {
            if (board[coords.y + y_i][coords.x + x_i] != '.')
                return (0);
        }
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
	int 	i;
	int		x_i;
	int		y_i;

	i = -1;
	while (++i < 4)
	{
		x_i = tetri->x_vec[i];
		y_i = tetri->y_vec[i];
		board[y + y_i][x + x_i] = tetri->id;
	}
}

/*
** Removes the tetrimino on the board such that the x and y 
** match the top left of the board. The tetrimino block 
** positions will be replaced with '.'s
*/

void	remove_tetrimino(char **board, t_tetrimino tetri, int x, int y)
{
	int 	i;
	int		x_i;
	int		y_i;

	i = -1;
	while (++i < 4)
	{
		x_i = tetri->x_vec[i];
		y_i = tetri->y_vec[i];
		board[y + y_i][x + x_i] = '.';
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
	t_coords	coords;
    t_tetrimino *cur_tetri;

	if (is_empty(dq))
        return (1);     
     coords = { .x  = -1, .y = -1 };
     while (++coords.y < n)
     {
         coords.x = -1;
         while (++coords.x < n)
         {
             if (is_safe(board, ft_lstpeek(dq), n, coords))
             {
                 cur_tetri = ft_lstpoptail(&dq);
                 place_tetrimino(board, cur_tetri, coords.x, coords.y);
                 if (backtrack(board, dq, n))
                     return (1);
                remove_tetrimino(board, cur_tetri, coords.x, coords.y);
                ft_lstpushhead(&dq, cur_tetri);
             }
         }
     }
     return (0);
}

void	fillit(t_board *minos)
{
	t_queue	*dq;
	int 	size;
	char	**board;
	int		sol_found;


	sol_found = 0;
	size = START_SIZE - 1;
	while (!sol_found)
	{
		size = size + 1;
		board = init_board(size);
		sol_found = backtrack(board, dq, size);
		if (sol_found)
			draw(board, size);
		free_board(board, size);
	}
	destroy_q(dq);
}
