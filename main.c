/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:13:06 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/02 19:10:18 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	t_graph **graph;
    int     i;

	graph = NULL;
	if (argc == 1)
		return (ft_printf("\n"));
	i = ft_validate(&graph, argv);
	//if (i != -1)
	//    ft_exit_adjacency(graph);
	//ft_printf("%d\n", i);
	main_alg(graph);
	ft_exit_adjacency(graph);
	return (0);
}
