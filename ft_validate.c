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

int		ft_line_pars_one(char *line, t_help **help)
{
	if (line[0] == '#')
		return (ft_check_comment(line,  help));
	else
		return (ft_check_format_one(*help, line));
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
	if (get_next_line(k , &line) > 0)
		n = get_ant_num(line);
	else
		return (-1);
	if (n < 0)
		return (-1);
	while (get_next_line(k, &line) > 0)
	{
		if (ft_line_pars_one(line, &help) == -1)
			break ;
		ft_strdel(&line);
	}
	if (!(ft_strchr(line, '-')))
	    return (-1);
	*graph = create_graph(help ,n);
	return (0);
}
