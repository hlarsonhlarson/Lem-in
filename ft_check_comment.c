/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 13:46:22 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/02 19:02:47 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_start(t_help *tmp)
{
	t_help	*help_find;

	help_find = tmp;
	while (help_find)
	{
		if (help_find->start == 1 || help_find->end == 1)
			return (-1);
		help_find = help_find->next;
	}
	return (0);
}

int		ft_check_comment(char *line, t_help **help)
{
	if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
	{
		if (check_start(*help) == -1)
			return (-1);
	}
    if (ft_strcmp(line, "##start") == 0)
        (*help)->start = 1;
    else if (ft_strcmp(line, "##end") == 0)
        (*help)->end = 1;
	return (0);
}
