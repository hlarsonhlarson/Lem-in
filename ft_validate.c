/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:01:50 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/02 17:02:38 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_ant_num(char *line)
{
	int		n;
	int		i;

	i = 0;
	n = ft_atoi(line);
	if (line[i] = '-')
		i++;
	if (line[i] < '0' || line[i] > '9')
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (count_numbers(n) != i || line[i] != '\0')
	{
		ft_strdel(&line);
		return (-1);
	}
	ft_strdel(&line);
	return (n);
}	

int		ft_line_pars_one(char *line, t_help *help)
{
	t_help	*tmp;

	tmp = help;
	while (help != NULL || help->start != 1 || help->end != 1)
		help = help->next;
	help = (help->start != 1 || help->end != 1) ? help :
		(t_help *)malloc(sizeof(t_help));
	if (line[0] == '#')
		return (ft_check_comment(line, tmp, help));
	else
		return (ft_check_format(line, help, tmp));
}

int		ft_validate(t_graph ***graph, char **argv)
{
	int		k;
	char	*c;
	char	*line;
	t_help	*help;
	int		n;

	k = open(argv[1], O_RDONLY);
	help = NULL;
	line = NULL;
	if (get_next_line(k , &line) > 0)
		n = get_ant_num(line);
	if (n < 0)
		return (-1);
	while (get_next_line(k, &line) > 0)
	{
		if (ft_line_pars_one(line, help) == -1)
			break ;
	}
	*graph = create_graph(help ,n);
}
