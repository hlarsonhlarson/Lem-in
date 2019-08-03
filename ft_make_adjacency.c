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
        return (-1);
    c = ft_strnew(ft_strlen(line) - i);
    c = ft_strcpy(c, line + i + 1);
    second_link = get_second_link(c, graph);
    if (second_link == -1)
    {
        ft_strdel(&c);
        return (-1);
    }
    (graph[first_link])->adjacency = graph[second_link];
    (graph[second_link])->adjacency = graph[first_link];
    ft_strdel(&c);
    return (0);
}