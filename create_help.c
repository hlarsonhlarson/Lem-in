/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 19:32:14 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/03 20:37:44 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_help(t_help *tmp, t_help *help)
{
	if (tmp == NULL)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = help;
}

t_help	*create_help(int *start, int *end)
{
	t_help	*help;

	help = (t_help *)malloc(sizeof(t_help));
	help->name = NULL;
	help->x = 0;
	help->y = 0;
	help->next = NULL;
	if (*start == 1 || *start == -1)
		help->start = 1;
	else
		help->start = 0;
	if (*end == 1 || *end == -1)
		help->end = *end;
	else
		help->end = 0;
	*start = 0;
	*end = 0;
	return (help);
}
