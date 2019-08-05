/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:45:41 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/05 14:06:09 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		empty_queue(t_queue queue)
{
	return ((head == tail) ? 1 : 0);
}

int		size_queue(t_queue queue)
{
	if (queue.head > queue.tail)
		return (queue.max_elem - head - tail);
	return (tail - head);
}

void	push_queue(t_queue queue, int x)
{
	if (size_queue(queue) != queue.max_elem)
	{
		queue.elements[tail] = x;
		tail = (tail + 1) % queue.max_elem;
	}
}

int		pop_queue(t_queue queue)
{
	int		x;

	if (empty_queue(queue))
		return (-1);
	x = queue.elements[head];
	head = (head + 1) % queue.max_elem;
	return (x);
}

t_queue	*init_queue(int size)
{
	t_queue	*queue;

	queue = (t_queue *)ft_memalloc(sizeof(t_queue));
	queue->elements = (int *)ft_memalloc(sizeof(int) * size);
	queue->max_elem = size;
	queue->head = 0;
	queue->tail = 0;
	return (queue);
}
