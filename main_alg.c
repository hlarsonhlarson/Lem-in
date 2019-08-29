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

	visited = (int *)ft_memalloc(sizeof(int) * queue->max_elem);
	parent = (int *)ft_memalloc(sizeof(int) * queue->max_elem);
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

	*path_len = 0;
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
		*path_len = *path_len + 1;
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

<<<<<<< HEAD
void        recreate_graph(t_graph **graph, int *path_num, t_organizer *organizer, int *path_len)
=======
t_adjacency		*recreate_graph(t_graph **graph, int *path_num, int start, int end)
>>>>>>> 7f752c4d536e73b4a9dd8d16d44ee5431a554ccc
{
	t_adjacency	*path;
	t_adjacency	*tmp_graph;
	t_adjacency	*head_path;

	path = get_way(path_num, organizer->end, path_len);
	head_path = path;
	while (path)
	{
		if (path->next == NULL)
<<<<<<< HEAD
		{
			ft_del_path(&head_path);
			return ;
		}
=======
			return (head_path);
>>>>>>> 7f752c4d536e73b4a9dd8d16d44ee5431a554ccc
		tmp_graph = graph[path->next->node_num]->adjacency;
		while (tmp_graph)
		{
			if (tmp_graph->node_num == path->node_num)
<<<<<<< HEAD
				tmp_graph->node_num = organizer->start;
=======
				tmp_graph->node_num = start;
>>>>>>> 7f752c4d536e73b4a9dd8d16d44ee5431a554ccc
			tmp_graph = tmp_graph->next;
		}
		path = path->next;
	}
}

<<<<<<< HEAD
void		print_way(int *path, int u, t_graph **graph)
{
	if (path[u] != u)
		print_way(path, path[u], graph);
	ft_printf("%s\n", graph[u]->name);
=======
void        print_way(t_adjacency *path, t_graph **graph)
{
	while (path)
	{
		ft_printf("%s\n", graph[path->node_num]->name);
		path = path->next;
	}
>>>>>>> 7f752c4d536e73b4a9dd8d16d44ee5431a554ccc
}

void		clear_queue(t_queue *queue, int start)
{
<<<<<<< HEAD
	ft_bzero(queue->elements, queue->max_elem);
	queue->head = 0;
	queue->tail = 0;
	push_queue(queue, (int)start);
}

t_path		*ft_add_path(int *path, int path_len, t_path *path_structed)
{
	t_path	*tmp;
	int	i;

	i = 0;
	tmp = path_structed;
	while (tmp)
		tmp = tmp->next;
	tmp = (t_path *)malloc(sizeof(t_path));
	tmp->path = (int *)malloc(sizeof(int) * path_len);
	while (i != path_len)
	{
		(tmp->path)[i] = path[i];
		i++;
	}
	tmp->path_len = path_len;
	tmp->next = 0;
	if (path_structed == NULL)
		path_structed = tmp;
	free(path);
	return (path_structed);
}

void		help_fun(t_graph **graph, t_organizer *organizer, t_path **path_pointer)
{
	t_queue *queue;
	t_path  *path_structed;
	int     *path;
	int	path_len;
	int path_num;

	path_structed = *path_pointer;
	queue = init_queue(organizer->len);
	push_queue(queue, organizer->start);
	path_num = count_path(graph, organizer->start);
	while (path_num != -1)
	{
		path = get_path(queue, graph, organizer);
		recreate_graph(graph, path, organizer, &path_len);
		path_structed = ft_add_path(path, path_len, path_structed);
		clear_queue(queue, organizer->start);
=======
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
>>>>>>> 7f752c4d536e73b4a9dd8d16d44ee5431a554ccc
		path_num--;
	}
	if (path == NULL)
		return ;
<<<<<<< HEAD
	free(queue->elements);
	free(queue);
	*path_pointer = path_structed;

=======
	print_way(path[0], graph);
	ft_printf("HI\n");
	print_way(path[1], graph);
>>>>>>> 7f752c4d536e73b4a9dd8d16d44ee5431a554ccc
}

void		main_alg(t_graph **graph)
{
	t_path		*path;
	t_organizer	organizer;

<<<<<<< HEAD
	path = NULL;
	get_graph_param(graph, &organizer);
	help_fun(graph, &organizer, &path);
	while (path)
	{
		int	i = 0;
		while (i != path->path_len)
		{
			printf("%s\n", graph[(path->path)[i]]);
			i++;
		}
		path = path->next;
	}
=======
	get_graph_param(graph, &start, &end, &len);
	help_fun(graph, start, end, len);
>>>>>>> 7f752c4d536e73b4a9dd8d16d44ee5431a554ccc
}
