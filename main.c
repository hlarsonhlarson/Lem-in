/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:13:06 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/02 15:53:23 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_line_pars(char *line, t_help *help)
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

int		main(int argc, char **argv)
{
	int		k;
	char	*c;
	char	*line;
	t_help	*help;

	if (argc == 1)
		return (ft_printf("\n"));
	k = open(argv[1], O_RDONLY);
	help = NULL;
	line = NULL;
	while (get_next_line(k, &line) > 0)
		ft_line_pars(line, help);
	ft_printf("%s\n", c);
	return (0);
}
