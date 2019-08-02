/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:21:12 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/02 17:06:04 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		count_elem(t_help *help)
{
	t_help	*tmp;
	int		i;

	i = 0;
	tmp = help;
	while(tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static void		copy_data_from_help(t_graph *graph, t_help *tmp)
{
		(graph)->name = tmp->name;
		(graph)->start = tmp->start;
		(graph)->end = tmp->end;
		(graph)->x = tmp->x;
		(graph)->y = tmp->y;
		(graph)->adjacment = NULL;
}

t_graph		**create_graph(t_help *help)
{
	t_graph		**graph;
	t_help		*tmp;
	t_help		*swap;
	int			i;

	i = 0;
	tmp = help;
	graph = (t_graph **)malloc(sizeof(t_graph **) * count_elem(help));
	while (tmp)
	{
		graph[i] = (t_graph *)malloc(sizeof(t_graph *));
		swap = tmp->next;
		copy_data_from_help(graph[i], tmp);
		ft_strdel(&(tmp->name));
		free(tmp);
		tmp = swap;
	}
	return (graph);
}
