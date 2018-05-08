/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:24:42 by tmatthew          #+#    #+#             */
/*   Updated: 2018/05/07 19:25:13 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Your executable must take only one parameter, a file which contains a list of
** Tetriminos to assemble.
** If the number of parameters sent to your executable is not
** 1, your program must display its usage and exit properly.
*/

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_putendl(fillit(parse_board(argv[1])));
	else
		fillit_print_usage();
	return (0);
}
