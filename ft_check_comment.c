/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 20:33:06 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/04 17:58:16 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_start(t_help *tmp)
{
	t_help	*help_find;

	help_find = tmp;
	while (help_find)
	{
		if (help_find->start == 1)
			return (-1);
		help_find = help_find->next;
	}
	return (0);
}

int		check_end(t_help *tmp)
{
	t_help	*help_find;

	help_find = tmp;
	while (help_find)
	{
		if (help_find->end == 1)
			return (-1);
		help_find = help_find->next;
	}
	return (0);
}

int		ft_check_comment_ant(char *line)
{
	if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
	{
		ft_strdel(&line);
		return (-1);
	}
	ft_strdel(&line);
	return (0);
}

int		ft_check_comment(char *line, t_help **help, int *start, int *end)
{
	if (ft_strcmp(line, "##start") == 0)
		*start = *start + 1;
	else if (ft_strcmp(line, "##end") == 0)
		*end = *end + 1;
	if (*start > 1 || *end > 1)
		return (ft_exit_checking(&line, help));
	if (ft_strcmp(line, "##start") == 0)
	{
		if (check_start(*help) == -1)
			return (ft_exit_checking(&line, help));
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (check_end(*help) == -1)
			return (ft_exit_checking(&line, help));
	}
	ft_strdel(&line);
	return (0);
}
