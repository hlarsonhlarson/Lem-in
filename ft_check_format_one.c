/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:33:11 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/02 15:38:07 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		find_char(char *line, char a)
{
	int		i;

	i = 0;
	while (line[i] != a || line[i])
		i++;
	return (i);
}

static int		ft_help_atoi(int x, char *line)
{
	int		i;

	i = 0;
	if (line[i] = '-')
		i++;
	if (line[i] < '0' || line[i] > '9')
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (count_numbers(x) != i)
		return (-1);
	if (line[i] != ' ' && line[i] != '\0')
		return (-1);
	return (0);
}

static int		ft_exit_format(t_help *help)
{
	free(help->name);
	return (-1);
}

static int		ft_check_name(t_help *help, t_help *tmp)
{
	while (tmp != help)
	{
		if (ft_strcmp(tmp->name, help->name) == 0)
			return (-1);
		tmp =tmp->next;
	}
	return (0);
}

int		ft_check_format_one(t_help *help, char *line)
{
	int		i;
	int		j;

	i = find_char(line, ' ');
	if (line[i] == '\0')
		return (-1);
	help->name = ft_strdup(ft_strrchr(line, ' '));
	if (ft_check_name == -1)
		return (ft_exit_format(help));
	help->x = ft_atoi(line + i + 1);
	if (ft_help_atoi(x, line + i + 1) == -1)
		return (ft_exit_format(help));
	i = find_char(line, ' ');
	if (line[i] == '\0')
		return (-1);
	help->y = ft_atoi(line + i + 1);
	if (ft_help_atoi(x, line + i + 1) == -1)
		return (ft_exit_format(help));
	i = find_char(line, ' ');
	return ((line[i] == '\0') ? 0 : ft_exit_format);
}
