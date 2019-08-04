/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 17:54:54 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/04 17:56:38 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_first_name(char *line, int i, t_help *help)
{
	int		k;
	t_help	*tmp;

	tmp = help;
	k = 0;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, line, i) == 0)
		{
			k = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if (k != 1)
		return (-1);
	return (0);
}

static int	check_second_name(char *c, t_help *help)
{
	int		k;
	t_help	*tmp;

	tmp = help;
	k = 0;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, c) == 0)
		{
			k = 1;
			break ;
		}
		tmp = tmp->next;
	}
	ft_strdel(&c);
	if (k != 1)
		return (-1);
	return (0);
}

int			check_start_elem(t_help *help)
{
	t_help	*tmp;

	tmp = help;
	while (tmp)
	{
		if (tmp->start == 1)
			return (1);
		tmp = tmp->next;
	}
	return (-1);
}

int			check_end_elem(t_help *help)
{
	t_help	*tmp;

	tmp = help;
	while (tmp)
	{
		if (tmp->end == 1)
			return (1);
		tmp = tmp->next;
	}
	return (-1);
}

int			check_first_line(char *line, t_help *help)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	if (line[i] == '\0')
		return (-1);
	if (check_first_name(line, i, help) == -1)
		return (-1);
	c = ft_strnew(ft_strlen(line) - i);
	c = ft_strcpy(c, line + i + 1);
	if (check_second_name(c, help) == -1)
		return (-1);
	if (check_start_elem(help) == -1)
		return (-1);
	if (check_end_elem(help) == -1)
		return (-1);
	return (0);
}
