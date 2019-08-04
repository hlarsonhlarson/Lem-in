/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:33:11 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/04 18:01:24 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		find_char(char *line, char a)
{
	int		i;

	i = 0;
	while (line[i] != a && line[i])
		i++;
	i++;
	return (i);
}

static int		ft_help_atoi(int x, char *line)
{
	int		i;

	i = 0;
	if (line[i] == '-')
		i++;
	if (line[i] < '0' || line[i] > '9')
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (count_num(x) != i)
		return (-1);
	if (line[i] != ' ' && line[i] != '\0')
		return (-1);
	return (0);
}

static int		ft_check_name(t_help *help, t_help *tmp)
{
	while (tmp != help && tmp)
	{
		if (ft_strcmp(tmp->name, help->name) == 0)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int				ft_get_num(t_help **help, char *line, int *i, int j)
{
	(*help)->x = ft_atoi(line + *i);
	if (ft_help_atoi((*help)->x, line + *i) == -1)
		return (-1);
	*i = *i + find_char(line + *i, ' ');
	if (*i > j)
		return (-1);
	(*help)->y = ft_atoi(line + *i);
	if (ft_help_atoi((*help)->y, line + *i) == -1)
		return (-1);
	*i = *i + find_char(line + *i, ' ');
	if (*i <= j)
		return (-1);
	return (0);
}

int				ft_check_format_one(t_help **help,
				char *line, int *start, int *end)
{
	int		i;
	t_help	*tmp;
	int		j;

	tmp = *help;
	j = ft_strlen(line);
	i = find_char(line, ' ');
	if (i > j)
		return ((check_first_line(line, tmp) == -1) ? ft_exit_checking(&line, &tmp) : 1);
	while (*help)
		*help = (*help)->next;
	*help = create_help(start, end);
	add_help(tmp, *help);
	(*help)->name = ft_copy_name(line, i);
	if (ft_check_name(*help, tmp) == -1)
		return (ft_exit_checking(&line, &tmp));
	if (ft_get_num(help, line, &i, j) == -1)
		return (ft_exit_checking(&line, &tmp));
	*help = (tmp == NULL) ? *help : tmp;
	ft_strdel(&line);
	return (0);
}
