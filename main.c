/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:13:06 by hlarson           #+#    #+#             */
/*   Updated: 2019/07/31 18:36:26 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	int		k;
	char	*c;
	char	*line = NULL;

	if (argc == 1)
		return (ft_printf("\n"));
	k = open(argv[1], O_RDONLY);
	c = ft_strdup("");
	while (get_next_line(k, &line) > 0)
		c = ft_strjoin(c, line);
	ft_printf("%s\n", c);
	return (0);
}
