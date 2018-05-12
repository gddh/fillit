/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:16:03 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/10 21:05:08 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Given a buffer containing a possible tetrimino and the {x,y} coordinates
** of a block, return the total number of blocks neighboring it above,
** below, and to the left and right
*/

static int				has_neighbor(char *mino, int col, int row)
{
	return ((col > 0 && mino[row * 4][col - 1] == '#' ? 1 : 0)
		+ (col < 4 && mino[row * 4][col + 1] == '#' ? 1 : 0)
		+ (row > 0 && mino[row * 4 - 1][col] == '#' ? 1 : 0)
		+ (row < 4 && mino[row * 4 + 1][col] == '#' ? 1 : 0));
}

/*
** add_tetrimino verifies that a potentional tetrimino has 4 neighboring cells
** then calculates each sub_tetrimino's position, adding them to the
** existing data structure
*/

static void	find_blocks(char *mino, t_tetrimino *new, int found)
{
	int		i;
	int		j;
	int		edges;
	int		neighbors;

	i = -1;
	edges = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (mino[i * 4][j] == '#' && found < 4
				&& (neighbors = has_neighbor(mino, i, j)))
			{
				new->x_vec[found * I_SIZE] = i;
				new->y_vec[found * I_SIZE] = j;
				new->name = 'A' + found++;
				edges += neighbors;
			}
			else if (mino[i * 4][j] != '.' || (i == 3 && j == 3 && edges < 6))
				fillit_exit();
		}
	}
}

/*
** Given the board and a possible tetrimino, verify that the possible piece
** conforms to the spec of a tetrimino, then add piece to the board dequeue
** after shifting up and left.
*/

static void		add_tetrimino(t_board board, char *tetrimino)
{
	t_tetrimino	new;
	char		*tmp;

	find_blocks(tetrimino, &new, 0);
	while (!ft_arrfoldl(zero_found, 4, I_SIZE, new.x_vec))
		ft_arriterl(sub_one, new.x_vec, 4, I_SIZE);
	while (!ft_arrfoldl(zero_found, 4, I_SIZE, new.y_vec))
		ft_arriterl(sub_one, new.y_vec, 4, I_SIZE);
	if (!(ft_lstadd(&(board->pieces), ft_lstnew(&new, sizeof(t_tetrimino)))))
		fillit_exit();
	board->count += 1;
}

/*
** Read file one line at a time, adding each to a buffer.
** Checks that each block is 4 lines, containing 4 chars, that each newline
** is preceded by 4 blocks, and the maximum number of tetrimino pieces is
** less than 26
** Returns a valid board or calls fillit_exit if invariants not met.
*/

static t_board		read_file(int fd, t_board board, char *possible, size_t i)
{
	int				next;
	char			*line;
	unsigned int	blocks;

	line = NULL;
	while ((next = get_next_line(fd, &line)) == 1)
	{
		if (!line && !ft_memchr(possible, EMPTY, 16))
			continue ;
		if ((!line && ft_memchr(possible, EMPTY, 16)) || ft_strlen(line) != 4
			|| i >= 4 || ft_lstsize(board->pieces) > 26)
			fillit_exit();
		ft_memcpy(possible, line, 4);
		possible += 4;
		if (i == 4)
		{
			add_tetrimino(board, *possible);
			ft_memset(possible, EMPTY, 16);
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
	char	possible_tetrimino[16];

	if (!path
		|| (fd = open(path, O_RDONLY)) == -1
		|| !(board = ft_memalloc(sizeof(t_board)))
		|| !(board->pieces = ft_memalloc(sizeof(t_list*))))
		fillit_exit();
	ft_memset(possible_tetrimino, EMPTY, 16);
	board->count = 0;
	board = read_file(fd, board, possible_tetrimino, 0);
	return (board);
}
