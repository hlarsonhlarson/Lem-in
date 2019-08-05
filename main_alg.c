/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:26:15 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/05 13:46:13 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		get_graph_len(t_graph **graph, size_t *start, size_t *end, size_t *len)
{
	*len = 0;
	while (graph[*len])
	{
		if (graph[*len]->start == 1)
			*start_num = *len;
		if (graph[*len]->end == 1)
			*end_num = *len;
		*len++;
	}
}

void		main_alg(t_graph **graph)
{
	size_t	start;
	size_t	end;
	size_t	len;
	int		*queue;
	int		*visited;

	get_graph_param(graph, &start, &end, &len);
	visited = (int *)malloc(sizeof(int) * len);
