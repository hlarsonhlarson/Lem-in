/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_disjoint_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:52:47 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/10 20:35:55 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			find_smallest(t_adjacency **path, int number_of_path)
{
	int		i;
	int		k;
	int		smallest_num;

	i = 0;
	while (path[number_of_path])
	{
		path[number_of_path] = path[number_of_path]->next;
		i++;
	}
	j = i;
	smallest_num = number_of_path;
	number_of_path--;
	while (number_of_path != -1)
	{
		while (path[number_of_path])
		{
			path[number_of_path] = path[number_of_path]->next;
			i++;
		}
		if (i < j)
			smallest_num = number_of_path;
	}
	return (smallest_num);
}

void		work_with_path(t_adjacency **path, int number_of_path, int smallest_index, t_adjacency *tmp)
{
	t_adjacency	*help;

	while(path[number_of_path]->next->node_num != tmp->node->num)
		path[number_of_path] = path[number_of_path]->next;
	help = path[number_of_path]->next;
	path[number_of_path]->next = tmp;
	while (help)
	{



void		ft_disjoint_path(t_adjacency **path, int number_of_path, int start, int end)
{
	int		smallest_index;
	int		i;
	t_adjacency	*tmp;
	t_adjacency	**big_tmp;

	big_tmp = path;
	i = number_of_path;
	smallest_index = find_smallest(path, number_of_path);
	while (path[smallest_index])
	{
		while (number_of_path != -1)
		{
			if (number_of_path == smallest_index)
				number_of_path--;
			while (path[number_of_path])
			{
				if (path[number_of_path]->node_num == path[smallest_index]->node_num
						&& path[number_of_path]->node_num != start
						&& path[number_of_path]->node_num != end)
				{
					tmp = path[smallest_index]->next;
					path[smallest_index]->next = path[number_of_path]->next;
					work_with_path(big_tmp, number_of_path, tmp);
					return (ft_disjoint_path(big_tmp, i, start, end));
				}
				path[number_of_path] = path[number_of_path]->next;
			}
		}
		path[smallest_index] = path[smallest_index]->next;
	}
	return ;
}
