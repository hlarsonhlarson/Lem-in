/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_adjacency.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:00:49 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/04 17:01:24 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int     ft_exit_adjacency(t_graph **graph)
{
    int     i;
    t_graph *tmp;

    i = 0;
    while (graph[i])
    {
        while (graph[i])
        {
            tmp = graph[i]->adjacency;
            ft_strdel(&(graph[i]->name));
            free(graph[i]);
            graph[i] = tmp;
        }
        i++;
    }
    free(graph);
    return (-1);
}

int     ft_exit_adjacency_norm(char *c, char *line)
{
	ft_strdel(&c);
	ft_strdel(&line);
	return (0);
}

int     ft_exit_adjacency_error(char *c, char *line, t_graph **graph)
{
	ft_strdel(&c);
	ft_strdel(&line);
	ft_exit_adjacency(graph);
	return (-1);
}

int     ft_exit_adjacency_error_two(char *line, t_graph **graph)
{
    ft_strdel(&line);
    ft_exit_adjacency(graph);
    return (-1);
}