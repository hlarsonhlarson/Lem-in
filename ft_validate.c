/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:01:50 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/02 19:19:21 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_ant_num(char *line)
{
	int		n;
	int		i;

	i = 0;
	n = ft_atoi(line);
	if (line[i] == '-')
		i++;
	if (line[i] < '0' || line[i] > '9')
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (count_num(n) != i || line[i] != '\0')
	{
		ft_strdel(&line);
		return (-1);
	}
	ft_strdel(&line);
	return (n);
}	

int     ft_get_ant_num(int k, char **line)
{
    int     n;

    n = 0;
    while (get_next_line(k, line) > 0)
    {
        if (*line[0] == '#')
        {
            if (ft_check_comment_ant(*line) < 0)
                return (-1);
        }
        else
        {
            n = get_ant_num(*line);
            if (n < 0)
                return (-1);
            return (n);
        }
    }
    return (-1);
}

int     ft_get_basic_coord(int k, char **line, t_help **help)
{
    int     start;
    int     end;
    int     l;

    start = 0;
    end = 0;
    while (get_next_line(k, line) > 0)
    {
        if (*line[0] == '#')
        {
            if (ft_check_comment(*line, help, &start, &end) < 0)
                return (-1);
        }
        else
            {
                if ((l =ft_check_format_one(help, *line, &start, &end)) < 0)
                    return (-1);
                if (l == 1)
                    return (0);
            }
    }
    return (-1);
}

int     ft_get_adjacency(char **line, t_graph **graph, int k)
{
    while (get_next_line(k, line) > 0)
    {
        if (*line[0] == '#')
        {
            if (ft_check_comment_ant(*line) < 0)
                return (-1);
        }
        else
        {
            if ((ft_make_adjacency(*line, graph)) < 0)
                return (-1);
        }
    }
    return (0);
}

int		ft_validate(t_graph ***graph, char **argv)
{
	int		k;
	char	*line;
	t_help	*help;
	int		n;

	k = open(argv[1], O_RDONLY);
	help = NULL;
	line = NULL;
	n = ft_get_ant_num(k, &line);
	if (n < 0)
		return (-1);
	if (ft_get_basic_coord(k, &line, &help) == -1)
	    return (-1);
	*graph = create_graph(help, n);
	put_first_adjacency(line, *graph);
	if (ft_get_adjacency(&line, *graph, k) == -1)
	    return (-1);
	ft_strdel(&line);
	return (0);
}
