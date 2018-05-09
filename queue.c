/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:26:41 by delin             #+#    #+#             */
/*   Updated: 2018/05/08 17:55:05 by delin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdio.h>

/*
** Creates a node for the queue. If there is not enough memory for malloc,
** the function will return NULL.
*/

t_queue	*create_node(t_qtype data)
{
	t_queue	*tmp;

	if ((tmp = (t_queue *)malloc(sizeof(t_queue))))
	{
		tmp->next = NULL;
		tmp->data = data;
	}
	return (tmp);
}

/*
** Add to the queue from the back.
** Just ft_list_push_back from the piscine
*/

void	enqueue_back(t_queue **q_front, t_qtype data)
{
	t_queue	*tmp;

	if (*q_front)
	{
		tmp = *q_front;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_node(data);
	}
	else
		*q_front = create_node(data);
}

/*
** Add to the queue from the front.
** Just ft_list_push_front from the piscine.
*/

void	enqueue_front(t_queue **q_front, t_qtype data)
{
	t_queue *tmp;

	if (*q_front)
	{
		tmp = create_node(data);
		tmp->next = (*q_front);
		*q_front = tmp;
	}
	else
		*q_front = create_node(data);
}

/*
** Dequeues from the beginning of the list.
** Returns the data of the item we are dequeuing
** Frees the node that we dequeue
** Uses ft_putstr_fd to print error message to STDERR if *q_front is NULL
*/

t_qtype	dequeue(t_queue **q_front)
{
	t_queue	*tmp;
	t_qtype	data;

	if (*q_front)
	{
		tmp = *q_front;
		data = tmp->data;
		*q_front = (*q_front)->next;
		free(tmp);
		return (data);
	}
	else
	{
		ft_putstr_fd("Cannot peek into an empty queue.\n", 2);
		exit(1);
	}
}
