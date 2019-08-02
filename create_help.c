/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 19:32:14 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/02 19:35:00 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_help	*create_help(void)
{
	t_help	*help;

	help = (t_help *)malloc(sizeof(t_help));
	help->name = NULL;
	help->x = 0;
	help->y = 0;
	help->next = NULL;
	help->start = 0;
	help->end = 0;
	return (help);
}
