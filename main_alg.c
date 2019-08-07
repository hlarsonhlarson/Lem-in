/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:26:15 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/07 16:55:22 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		get_graph_param(t_graph **graph, size_t *start, size_t *end, size_t *len)
{
	*len = 0;
	while (graph[*len])
	{
		if ((graph[*len])->start == 1)
			*start = *len;
		if (graph[*len]->end == 1)
			*end = *len;
		*len = *len + 1;
	}
}

int			*get_path(t_queue *queue, t_graph **graph, int start, int end)
{
	int		*visited;
	int		*parent;
	int		node_num;
	t_adjacency	*adjacency;

	visited = (int *)ft_memalloc(sizeof(int) * queue->max_elem);
	visited[start] = 1;
	parent = (int *)ft_memalloc(sizeof(int) * queue->max_elem);
	while (!empty_queue(*queue))
	{
		node_num = pop_queue(queue);
		if (node_num == end)
        {
		    free(visited);
		    return (parent);
        }
		adjacency = graph[node_num]->adjacency;
		while (adjacency)
		{
			if (visited[adjacency->node_num] == 0)
			{
				parent[adjacency->node_num] = node_num;
				push_queue(queue, adjacency->node_num);
			}
            adjacency = adjacency->next;
		}
		visited[node_num] = 1;
	}
	free(visited);
	return (NULL);
}

void		print_way(int *path, t_graph **graph, int u)
{
	if (path[u] != u)
		print_way(path, graph, path[u]);
	ft_printf("%s\n", graph[u]->name);
}

void		main_alg(t_graph **graph)
{
	size_t	start;
	size_t	end;
	size_t	len;
	t_queue	*queue;
	int		*path;

	get_graph_param(graph, &start, &end, &len);
	queue = init_queue(len);
	push_queue(queue, (int)start);
	path = get_path(queue, graph, start, end);
	if (path == NULL)
	    return ;
	print_way(path, graph, (int)end);
	free(path);
	free(queue->elements);
	free(queue);
}
