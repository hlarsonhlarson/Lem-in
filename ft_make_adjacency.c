/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_adjacency.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:35:58 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/03 17:36:04 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int get_first_name(char *line, int i, t_graph **graph)
{
    int     j;
    int     k;

    j = 0;
    k = 0;
    while (graph[j])
    {
        if (ft_strncmp((graph[j])->name, line, i) == 0)
        {
            k = 1;
            break ;
        }
        j++;
    }
    if (k == 0)
        return (-1);
    return (j);
}

static int get_second_link(char *line,  t_graph **graph)
{
    int     j;
    int     k;

    j = 0;
    k = 0;
    while (graph[j])
    {
        if (ft_strcmp((graph[j])->name, line) == 0)
        {
            k = 1;
            break ;
        }
        j++;
    }
    if (k == 0)
        return (-1);
    return (j);
}

static void        connet_link(t_graph **graph, int first_link, int second_link)
{
    t_adjacency *tmp;
    t_adjacency *another_tmp;

    tmp = graph[first_link]->adjacency;
    while (tmp && tmp->next)
        tmp = tmp->next;
    if (tmp != NULL)
        tmp->next = make_adjacency(second_link);
    else
        graph[first_link]->adjacency = make_adjacency(second_link);
    another_tmp = graph[second_link]->adjacency;
    while (another_tmp && another_tmp->next)
        another_tmp = another_tmp->next;
    if (another_tmp != NULL)
        another_tmp->next = make_adjacency(first_link);
    else
        graph[second_link]->adjacency = make_adjacency(first_link);
}

int        ft_make_adjacency(char *line, t_graph **graph)
{
    int     i;
    char    *c;
    int     first_link;
    int     second_link;

    i = 0;
    while (line[i] && line[i] != '-')
        i++;
    first_link = get_first_name(line, i, graph);
    if (first_link == -1)
        return (ft_exit_adjacency_error_two(line, graph));
    c = ft_strnew(ft_strlen(line) - i);
    c = ft_strcpy(c, line + i + 1);
    second_link = get_second_link(c, graph);
    if (first_link == second_link || second_link == -1)
        return (ft_exit_adjacency_error(c, line, graph));
    connet_link(graph, first_link, second_link);
    return (ft_exit_adjacency_norm(c, line));
}