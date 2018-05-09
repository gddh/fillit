/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:26:47 by delin             #+#    #+#             */
/*   Updated: 2018/05/08 18:05:44 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "stdlib.h"
# include "libft/libft.h"
# include "fillit.h"

typedef t_tetrimino	*t_qtype;
typedef struct		s_queue
{
	struct s_queue	*next;
	t_qtype			data;
}					t_queue;

t_queue				*init_queue();
void				enqueue_back(t_queue **q_front, t_qtype data);
t_qtype				dequeue(t_queue **q_front);
int					is_empty(t_queue *q);
int					size(t_queue *q);
t_queue				*create_node(t_qtype data);
t_qtype				peek(t_queue *q);
void				destroy_q(t_queue **q);

#endif
