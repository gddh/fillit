/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:26:08 by delin             #+#    #+#             */
/*   Updated: 2018/05/08 17:56:22 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

/*
** Frees the entire queue
** the q pointer is set to null
*/

void	destroy_q(t_queue **q)
{
	while (!is_empty(*q))
		dequeue(q);
}

/*
** Gives us the size of the queue.
** This may be unnecessary.
*/

int		size(t_queue *q)
{
	int count;

	count = 0;
	while (q)
	{
		q = q->next;
		count++;
	}
	return (count);
}

/*
** Return the element at the beginning of the queue
*/

t_qtype	peek(t_queue *q)
{
	if (!is_empty(q))
		return (q->data);
	else
	{
		ft_putstr_fd("Cannot peek into an empty queue.\n", 2);
		exit(1);
	}
}

/*
** Initializes the queue to null.
** Here to keeping abstraction barriers.
*/

t_queue	*init_queue(void)
{
	return (NULL);
}

/*
** Checks to see if the queue is empty.
** The queue is empty if it is null.
*/

int		is_empty(t_queue *q)
{
	return (q == NULL);
}
