/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:33:50 by delin             #+#    #+#             */
/*   Updated: 2018/05/08 16:35:20 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
# define BOARD_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

void	draw(char **board, int n);
char	**init_board(int n);

#endif
