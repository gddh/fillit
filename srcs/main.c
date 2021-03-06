/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:19:52 by delin             #+#    #+#             */
/*   Updated: 2018/05/12 16:01:11 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	fillit_print_usage(void)
{
	ft_putendl("usage: fillit [source_file]");
	exit(1);
}
/*
** Your executable must take only one parameter, a file which contains a list of
** Tetriminos to assemble.
** If the number of parameters sent to your executable is not
** 1, your program must display its usage and exit properly.
*/

int		main(int argc, char **argv)
{
	if (argc == 2)
		fillit(parse_board(argv[1]));
	else
		fillit_print_usage();
	return (0);
}
