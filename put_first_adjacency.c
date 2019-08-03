/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_first_adjacency.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:09:48 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/03 17:09:57 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int get_first_name(char *line, int i, t_graph **graph)
{
    int     j;

    j = 0;
    while (graph[j])
    {
        if (ft_strncmp((graph[j])->name, line, i) == 0)
            break ;
        j++;
    }
    return (j);
}

static int get_second_link(char *line,  t_graph **graph)
{
    int     j;

    j = 0;
    while (graph[j])
    {
        if (ft_strcmp((graph[j])->name, line) == 0)
            break ;
        j++;
    }
    return (j);
}

void        put_first_adjacency(char *line, t_graph **graph)
{
    int     i;
    char    *c;
    int     first_link;
    int     second_link;

    i = 0;
    while (line[i] && line[i] != '-')
        i++;
    first_link = get_first_name(line, i, graph);
    c = ft_strnew(ft_strlen(line) - i);
    c = ft_strcpy(c, line + i + 1);
    second_link = get_second_link(c, graph);
    (graph[first_link])->adjacency = graph[second_link];
    (graph[second_link])->adjacency = graph[first_link];
    ft_strdel(&c);
}