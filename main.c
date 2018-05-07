#include "fillit.h"

typedef struct	s_board
{
	void		*x_vec;
	void		*y_vec;
	void		*origins;
	int			pieces;
}				t_board;

/*
** add_to_vec copies a buffer into new memory, then appends given int
** frees the existing memory reference
*/

void	add_to_vec(void **vec, int val, int offset)
{
	void	*tmp;

	if (!(tmp = ft_memalloc(offset + sizeof(int))))
		fillit_exit();
	tmp = ft_memcpy(tmp, *vec);
	tmp += offset;
	*((int*)tmp) = get_x(next);
	ft_strdel(vec);
	*vec = tmp;
}

/*
** add_tetrimino verifies that a potentional tetrimino has only 4 cells,
** then calculates each sub_tetrimino's position, adding them to the
** existing data structure
*/

void	add_tetrimino(t_board board, char **tetrimino)
{
	int		i;
	int		next;
	int		offset;

	i = -1;
	while (++i < 4)
	{
		while ((next = ft_strchr(tetrimino[i], '#') - tetrimino))
		{
			offset = sizeof(int) * board->pieces;
			add_to_vec(&(board->x_vec), next, offset);
			add_to_vec(&(board->y_vec), next, offset);
			add_to_vec(&(board->origins), NULL, offset);
			tetrimino[next] += next;
			board->pieces += 1;
		}
	}
}

/*
** The description of a Tetriminos must respect the following rules :
** • Each block of a Tetrimino must touch at least one other block on any of his 
** 	4 sides (up, down, left and right).
*/

void		verify_prev_tetrimino(char **tetrimino, int i)
{
	int		index;

	index = 0;
	if (i != 5)
		fillit_exit();
	while (index < 5)
	{
		if (!tetrimino[index++])
			fillit_exit();
	}
}

/*
** The description of a Tetriminos must respect the following rules :
** • Each block of a Tetrimino must touch at least one other block on any of his 
** 	4 sides (up, down, left and right).
*/

int		neighbors(char *tetrimino, int x, int y)
{
}

/*
** The description of a Tetriminos must respect the following rules :
** • A Tetrimino is a classic piece of Tetris composed of 4 blocks.
** • Each character must be a block character(’#’) or an empty character (’.’).
** • Each block of a Tetrimino must touch at least one other block on any of his 
** 	4 sides (up, down, left and right).
*/

int valid_tetrimino(char *possible)
{
	int		occurrences;
	size_t		i;
	size_t		j;

	i = -1;
	occurrences = 0;
	while (possible[++i])
	{
		j = -1;
		while (possible[i][++j])
		{
			if (possible[i][j] == '#')
			{
				occurrences += 1;
				if (occurrences > 4 || !(neighbors(possible, i, j)))
					fillit_exit();
			}
			else if (possible[i][j] != '.')
				fillit_exit();
		}
	}
	return (1);
}

/*
** The description of a Tetriminos must respect the following rules :
** • Every Tetrimino must exactly fit in a 4 by 4 chars square and all Tetrimino
**	are separated by an newline each.
** • Precisely 4 lines of 4 chars, each followed by a new line (a 4x4 square).
** Your file should contain between 1 and 26 Tetriminos.
*/

t_board		read_file(int fd, t_board board, char **possible_tetrimino)
{
	size_t	i;
	int		next;
	char	*line;

	i = 0;
	line = NULL;
	while ((next = get_next_line(fd, &line)) == 1)
	{
		if (!line)
			verify_prev_tetrimino(possible_tetrimino, i);
		if (ft_strlen(line) != 4)
			fillit_exit();
		possible_tetrimino[i] = line;
		if (i == 4 && valid_tetrimino(possible_tetrimino))
		{
			add_tetrimino(board, possible_tetrimino);
			ft_memset(possible_tetrimino, NULL, (char*) * 4);
		}
		else if (i++ <= 4 || board->pieces > 26)
			fillit_exit();
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
	char	**possible_tetrimino;

	if (!path 
		|| (fd = open(path, O_RDONLY) == -1
		|| !(board = ft_memalloc(sizeof(t_board)))
		|| !(board->x_vec = ft_memalloc(sizeof(int)))
		|| !(board->y_vec = ft_memalloc(sizeof(int)))
		|| !(board->origins = ft_memalloc(sizeof(int)))
		|| !(possible_tetrimino = ft_memalloc((char**) * 5)))
		fillit_exit();
	board->pieces = 0;
	board = read_file(fd, board, possible_tetrimino);
	ft_strdel(&possible_tetrimino);
	return (board);
}

/*
** Your executable must take only one parameter, a file which contains a list of
** Tetriminos to assemble. 
** If the number of parameters sent to your executable is not
** 1, your program must display its usage and exit properly. 
*/

int     main(int argc, char **argv)
{
	if (argc == 2)
		ft_putendl(fillit(parse_board(argv[1])));
	else
		fillit_print_usage();
	return (0);
}
