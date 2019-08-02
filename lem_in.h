/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:57:01 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/02 15:35:23 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

typedef struct		s_graph
{
	char			*name;
	int				ant_number;
	struct s_graph	*adjacency;
	bool			start;
	bool			end;
}					t_graph;

typedef struct		s_help
{
	char			*name;
	struct s_help	*next;
	bool			start;
	bool			end;
	int				x;
	int				y;
}					t_help;

int					ft_check_comment(char *line, t_help *start, t_help *help);
int					ft_check_format(char *line, t_help *start, t_help *help);

#endif
