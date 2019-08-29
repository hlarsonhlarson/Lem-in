/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:07:39 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/29 14:00:31 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	change_paths(t_path *first_path, t_path *second_path)
{
	t_adjacency	*tmp;
	t_adjacency	*second_tmp;

	tmp = second_path->path->next->next;
	second_tmp = first_path->path->next;
    second_path->path->next = second_tmp;
	first_path->path->next = tmp->next;
	free(tmp);
}

void	search_overlapping(t_path *first_path, t_path *second_path, t_organizer *organizer)
{
	t_path	*first_tmp;
	t_path	*second_tmp;
	t_adjacency  *path_tmp_one;
	t_adjacency  *path_tmp_two;

	path_tmp_one = first_path->path;
	path_tmp_two = second_path->path;
	second_tmp = second_path;
	while (second_tmp->path->next)
	{
		first_tmp->path = path_tmp_one;
		while (first_tmp->path->next)
		{
			if (second_tmp->path->next->node_num == first_tmp->path->next->node_num
					&& first_tmp->path->next->node_num != organizer->start
					&& first_tmp->path->next->node_num != organizer->end)
            {
			    change_paths(first_tmp, second_tmp);
                first_tmp->path = path_tmp_one;
                while (first_tmp->path)
                {
                    ft_printf("%d\n", first_tmp->path->node_num);
                    first_tmp->path = first_tmp->path->next;
                }
                ft_printf("HI\n");
                second_tmp->path = path_tmp_two;
                while (second_tmp->path)
                {
                    ft_printf("%d\n", second_tmp->path->node_num);
                    second_tmp->path = second_tmp->path->next;
                }
                return ;
            }
		   first_tmp->path = first_tmp->path->next;
		 } 
		second_tmp->path = second_tmp->path->next;
	}
}

void	work_with_path(t_path *path, t_organizer *organizer)
{
	while (path && path->next)
	{
		search_overlapping(path, path->next, organizer);
		path = path->next;
	}
}
