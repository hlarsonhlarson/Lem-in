/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:26:15 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/10 17:44:52 by hlarson          ###   ########.fr       */
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

static int  *norm_exit(int *parent, int **visited)
{
	free(*visited);
	return (parent);
}

int			*get_path(t_queue *queue, t_graph **graph, int start, int end)
{
	int		*visited;
	int		*parent;
	int		node_num;
	t_adjacency	*adjacency;

	visited = (int *)ft_memalloc(sizeof(int) * queue->max_elem);
	parent = (int *)ft_memalloc(sizeof(int) * queue->max_elem);
	parent[start] = start;
	while (!empty_queue(*queue))
	{
		node_num = pop_queue(queue);
		if (node_num == end)
			return (norm_exit(parent, &visited));
		visited[node_num] = 1;
		adjacency = graph[node_num]->adjacency;
		while (adjacency)
		{
			if (visited[adjacency->node_num] == 0)
			{
				parent[adjacency->node_num] = node_num;
				visited[adjacency->node_num] = 1;
				push_queue(queue, adjacency->node_num);
			}
			adjacency = adjacency->next;
		}
	}
	free(visited);
	return (NULL);
}

t_adjacency		*get_way(int *path, int u)
{
	t_adjacency	*adj;
	t_adjacency	*tmp;

	adj = (t_adjacency *)malloc(sizeof(t_adjacency));
	adj->node_num = u;
	adj->next = NULL;
	tmp = adj;
	u = path[u];
	while (u != path[u])
	{
		adj->next = (t_adjacency *)malloc(sizeof(t_adjacency));
		adj->next->node_num = u;
		adj->next->next = NULL;
		adj = adj->next;
		u = path[u];
	}
	adj->next = (t_adjacency *)malloc(sizeof(t_adjacency));
	adj->next->node_num = u;
	adj->next->next = NULL;
	return (tmp);
}

size_t      count_path(t_graph **graph, size_t start)
{
	t_adjacency *adjacency;
	size_t      counter;

	counter = 0;
	adjacency = graph[start]->adjacency;
	while (adjacency)
	{
		adjacency = adjacency->next;
		counter++;
	}
	counter--;
	return (counter);
}

void		ft_del_path(t_adjacency **head_path)
{
	t_adjacency	*tmp;
	t_adjacency	*swap;

	tmp = *head_path;
	while (tmp)
	{
		swap = tmp->next;
		free(tmp);
		tmp = swap;
	}
}

t_adjacency		*recreate_graph(t_graph **graph, int *path_num, int start, int end)
{
	t_adjacency	*path;
	t_adjacency	*tmp_graph;
	t_adjacency	*head_path;

	path = get_way(path_num, end);
	head_path = path;
	while (path)
	{
		if (path->next == NULL)
			return (head_path);
		tmp_graph = graph[path->next->node_num]->adjacency;
		while (tmp_graph)
		{
			if (tmp_graph->node_num == path->node_num)
				tmp_graph->node_num = start;
			tmp_graph = tmp_graph->next;
		}
		path = path->next;
	}
}

void        print_way(t_adjacency *path, t_graph **graph)
{
	while (path)
	{
		ft_printf("%s\n", graph[path->node_num]->name);
		path = path->next;
	}
}

void        help_fun(t_graph **graph, size_t start, size_t end, size_t len)
{
	t_queue *queue;
	t_adjacency	**path;
	int  path_num;

	queue = init_queue(len);
	push_queue(queue, (int)start);
	path_num = count_path(graph, start);
	path = (t_adjacency **)malloc(sizeof(t_adjacency) * (int)path_num);
	while (path_num != -1)
	{
		path[path_num] = recreate_graph(graph,
				get_path(queue, graph, start, end), start, end);
		free(queue->elements);
		free(queue);
		queue = init_queue(len);
		push_queue(queue, (int)start);
		path_num--;
	}
	if (path == NULL)
		return ;
	print_way(path[0], graph);
	ft_printf("HI\n");
	print_way(path[1], graph);
}

void		main_alg(t_graph **graph)
{
	size_t	start;
	size_t	end;
	size_t	len;

	get_graph_param(graph, &start, &end, &len);
	help_fun(graph, start, end, len);
}
