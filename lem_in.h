/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:57:01 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/02 19:44:13 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "ft_printf/ft_printf.h"
# include <stdbool.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

typedef struct		s_graph
{
	char			*name;
	int				ant_number;
	struct s_graph	*adjacency;
	bool			start;
	bool			end;
	int				x;
	int				y;
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

int					ft_check_comment(char *line, t_help *start, t_help **help);
int					ft_check_format_one(t_help *help, char *line, t_help *head);
t_graph				**create_graph(t_help *help, int n);
int					ft_validate(t_graph ***graph, char **argv);
int					count_num(int k);
t_help				*create_help(void);
char				*ft_copy_name(char *line, int i);

#endif
