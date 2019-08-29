/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:26:15 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/29 12:59:53 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

void		get_graph_param(t_graph **graph, t_organizer *organizer)
{
	organizer->len = 0;
	while (graph[organizer->len])
	{
		if ((graph[organizer->len])->start == 1)
			organizer->start = organizer->len;
		if (graph[organizer->len]->end == 1)
			organizer->end = organizer->len;
		organizer->len = organizer->len + 1;
	}
}

static int  *norm_exit(int *parent, int **visited)
{
	free(*visited);
	return (parent);
}

int			*get_path(t_queue *queue, t_graph **graph, t_organizer *organizer)
{
	int		*visited;
	int		*parent;
	int		node_num;
	t_adjacency	*adjacency;

	visited = (int *)malloc(sizeof(int) * queue->max_elem);
	parent = (int *)malloc(sizeof(int) * queue->max_elem);
	parent[organizer->start] = organizer->start;
	while (!empty_queue(*queue))
	{
		node_num = pop_queue(queue);
		if (node_num == organizer->end)
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

t_adjacency		*get_way(int *path, int u, int *path_len)
{
	t_adjacency	*adj;
	t_adjacency	*tmp;

	adj = (t_adjacency *)malloc(sizeof(t_adjacency));
	adj->node_num = u;
	adj->next = NULL;
	tmp = adj;
	u = path[u];
	*path_len = 1;
	while (u != path[u])
	{
		adj->next = (t_adjacency *)malloc(sizeof(t_adjacency));
		adj->next->node_num = u;
		adj->next->next = NULL;
		adj = adj->next;
		u = path[u];
		*path_len = *path_len + 1;
	}
	*path_len = *path_len + 1;
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

t_path		*ft_add_path(t_adjacency *head_path, int path_len, t_path *path_structed)
{
	t_path	*tmp;

	tmp = path_structed;

	if (!tmp)
	{
		tmp = (t_path *)malloc(sizeof(t_path));
		tmp->path_len = path_len;
		tmp->next = NULL;
		tmp->path = head_path;
		return (tmp);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_path *)malloc(sizeof(t_path));
	tmp->next->path_len = path_len;
	tmp->next->next = NULL;
	tmp->next->path = head_path;
	return (path_structed);
}

void        recreate_graph(t_graph **graph, int *path_num, t_organizer *organizer, t_path **path_result)
{
	t_adjacency	*path;
	t_adjacency	*tmp_graph;
	t_adjacency	*head_path;
	int         path_len;

	path = get_way(path_num, organizer->end, &path_len);
	head_path = path;
	while (path)
	{
		if (path->next == NULL)
		{
			*path_result = ft_add_path(head_path, path_len, *path_result);
			return ;
		}
		tmp_graph = graph[path->next->node_num]->adjacency;
		while (tmp_graph)
		{
			if (tmp_graph->node_num == path->node_num)
				tmp_graph->node_num = organizer->start;
			tmp_graph = tmp_graph->next;
		}
		path = path->next;
	}
}

void		print_way(int *path, int u, t_graph **graph)
{
	if (path[u] != u)
		print_way(path, path[u], graph);
	ft_printf("%s\n", graph[u]->name);
}

void		clear_queue(t_queue *queue, int start)
{
	ft_bzero(queue->elements, queue->max_elem);
	queue->head = 0;
	queue->tail = 0;
	push_queue(queue, (int)start);
}

void		help_fun(t_graph **graph, t_organizer *organizer, t_path **path_pointer)
{
	t_queue *queue;
	t_path  *path_structed;
	int     *path;;
	int path_num;

	path_structed = *path_pointer;
	queue = init_queue(organizer->len);
	push_queue(queue, organizer->start);
	path_num = count_path(graph, organizer->start);
	while (path_num != -1)
	{
		path = get_path(queue, graph, organizer);
		if (path == NULL)
			break ;
		recreate_graph(graph, path, organizer, &path_structed);
		clear_queue(queue, organizer->start);
		path_num--;
	}
	if (path == NULL)
		return ;
	free(queue->elements);
	free(queue);
	*path_pointer = path_structed;
}

void		main_alg(t_graph **graph)
{
	t_path		*path;
	t_organizer	organizer;

	path = NULL;
	get_graph_param(graph, &organizer);
	help_fun(graph, &organizer, &path);
	work_with_path(path, &organizer);
/*	while (path)
	{
		t_adjacency *tmp;

		tmp = path->path;
		while (tmp)
		{
			printf("%s %d\n", graph[(tmp->node_num)]->name, path->path_len);
			tmp = tmp->next;
		}
		path = path->next;
	}*/
}
