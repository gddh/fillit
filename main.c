/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:19:52 by delin             #+#    #+#             */
/*   Updated: 2018/05/08 15:20:04 by delin            ###   ########.fr       */
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
