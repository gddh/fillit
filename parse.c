/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:16:03 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/07 22:34:29 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** add_tetrimino verifies that a potentional tetrimino has 4 cells that all touch
** each other at least once then calculates each sub_tetrimino's position, adding them to the
** existing data structure
*/

int			has_neighbor(t_tetrimino tetrimino, int row, int col)
{
	// since we know the {x,y}, just check surrounding squares
}

t_tetrimino	find_pos(t_tetrimino mino, int i, int j, int neighbor)
{
	while (++i < 4)
	{
		while (++j < 4)
		{
			if (mino[i * 4][j] == BLOCK && has_neighbor(mino, i * 4, j))
			{
				board->x_vec[I_SIZE * board->count] = i;
				board->y_vec[I_SIZE * board->count] = j;
			}
			else if (mino[i * 4][j] != SPACE)
				fillit_exit();
		}
	}
	while (!ft_arrfoldl(zero_found, x_vec, 4, I_SIZE))
		ft_arriterl(sub_one, x_vec, 4, I_SIZE);
	while (!ft_arrfoldl(zero_found, y_vec, 4, I_SIZE))
		ft_arriterl(add_one, y_vec, 4, I_SIZE);
	return (mino);
}

void		add_tetrimino(t_board board, char *tetrimino)
{
	t_tetrimino		new[sizeof(t_tetrimino)];

	ft_memmset(&(tetrimino.x_vec), EMPTY, I_SIZE * 4);
	ft_memmset(&(tetrimino.y_vec), EMPTY, I_SIZE * 4);
	if (!(board->pieces = resize_buf(board->pieces
			, board->count * I_SIZE
			, find_pos(new, 0, -1, 0)
			, sizeof(t_tetrimino))))
		fillit_exit();
	board->count += 1;
}

/*
** The description of a Tetriminos must respect the following rules :
** • Every Tetrimino must exactly fit in a 4 by 4 chars square and all Tetrimino
**	are separated by an newline each.
** • Precisely 4 lines of 4 chars, each followed by a new line (a 4x4 square).
** Your file should contain between 1 and 26 Tetriminos.
*/

t_board		read_file(int fd, t_board board, char *possible)
{
	size_t			i;
	int				next;
	char			*line;
	unsigned int	blocks;

	i = 0;
	line = NULL;
	while ((next = get_next_line(fd, &line)) == 1)
	{
		if (!line)
			continue();
		if (ft_strlen(line) != 4 || i >= 4 || board->pieces > 26)
			fillit_exit();
		*possible = line;
		possible += 4;
		if (i == 4)
		{
			add_tetrimino(board, *possible);
			ft_memset(possible, NULL, 16);
		}
		ft_strdel(&line);
	}
	if (next == -1)
			fillit_exit();
	return (board);
}

/*
** Initializes the buffers needes to store tetrimino block coordinates,
** opens the given file path, then calls read_file to parse tetriminos 
** returns a valid board or calls fillit_exit() 
*/

t_board		*parse_board(char *path)
{
	int		fd;
	t_board	*board;
	char	*possible;

	if (!path 
		|| (fd = open(path, O_RDONLY) == -1
		|| !(board = ft_memalloc(sizeof(t_board)))
		|| !(possible_tetrimino = ft_memalloc(16))
		fillit_exit();
	board->count = 0;
	board = read_file(fd, board, possible_tetrimino);
	ft_strdel(&possible_tetrimino);
	return (board);
}