/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:16:03 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/09 18:33:34 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** helper function for the arr iter, mutate arr by subtracting 1 from each elem
*/

void			sub_one(void *final, void *elem, size_t i, int *stop)
{
	(void)final;
	(void)stop;
	(void)i;
	*(int*)elem -= 1;
}

/*
** helper function for the reduce function, stops and returns if a 0 is found
*/

static void			*zero_found(void *final, void *elem, size_t i, int *stop)
{
	(void)final;
	(void)i;
	*stop = *(int*)elem == 0 ? 1 : 0;
	return (elem)
}

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

static t_tetrimino	find_blocks(char *mino, t_tetrimino *new, int found)
{
	int		i;
	int		j;
	int		edges;

	i = -1;
	edges = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (mino[i * 4][j] == '#' && found < 4 && has_neighbor(mino, i, j);
			{
				new->x_vec[found * I_SIZE] = i;
				new->y_vec[found * I_SIZE] = j;
				new->name = 'A' + found++;
				edges += has_neighbor(mino, i, j);
			}
			else if (mino[i * 4][j] != '.')
				fillit_exit();
		}
	}
	if (edges < 6)
		fillit_exit();
	return (mino);
}

/*
** TODO: add tetrimino to dequeue instead of buffer
*/

static void		add_tetrimino(t_new board, char *tetrimino)
{
	t_tetrimino	new_mino[sizeof(t_tetrimino)];
	size_t		new_size;

	new.edges = 0;
	new = find_blocks(tetrimino, &new, 0);
	while (!ft_arrfoldl(zero_found, new_mino.x_vec, 4, I_SIZE))
		ft_arriterl(sub_one, new_mino.x_vec, 4, I_SIZE);
	while (!ft_arrfoldl(zero_found, new_mino.y_vec, 4, I_SIZE))
		ft_arriterl(sub_one, new_mino.y_vec, 4, I_SIZE);
	if (!(tmp = ft_realloc(board->pieces, BLOCK_SIZE * board->count)))
		fillit_exit();
	board->pieces = ft_strcat(tmp, new_mino);
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
		else if (!line && ft_memchr(possible, EMPTY, 16))
			fillit_exit();
		if (ft_strlen(line) != 4 || i >= 4 || board->pieces > 26)
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
	char	possible[16];

	if (!path
		|| (fd = open(path, O_RDONLY)) == -1
		|| !(board = ft_memalloc(sizeof(t_board))))
		fillit_exit();
	ft_memset(possible, EMPTY, 16);
	board->count = 0;
	board = read_file(fd, board, possible_tetrimino, 0);
	return (board);
}
