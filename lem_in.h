/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:57:01 by hlarson           #+#    #+#             */
/*   Updated: 2019/08/03 20:40:13 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "ft_printf/ft_printf.h"
# include <stdbool.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

typedef struct      s_queue
{
    int     *elements;
    int     head;
    int     tail;
    int     max_elem;
}                   t_queue;


typedef struct      s_adjacency
{
    int                 node_num;
    struct s_adjacency  *next;
}                   t_adjacency;

typedef struct		s_path
{
    t_adjacency	*path;
    int	path_len;
    struct s_path	*next;
}			t_path;

typedef struct		s_graph
{
	char			*name;
	int				ant_number;
	t_adjacency	    *adjacency;
    char			start;
    char			end;
	int				x;
	int				y;
}					t_graph;

typedef struct		s_help
{
	char			*name;
	struct s_help	*next;
    char			start;
    char			end;
	int				x;
	int				y;
}					t_help;

typedef struct		s_organizer
{
	int	start;
	int	len;
	int	end;
}			t_organizer;

int					ft_check_comment(char *line, t_help **help, int *start, int *end);
int                 ft_check_comment_ant(char *line);
int					ft_check_format_one(t_help **help, char *line, int *start, int *end);
int                 check_first_line(char *line, t_help *help);
t_graph				**create_graph(t_help *help, int n);
int					ft_validate(t_graph ***graph, char **argv);
int					count_num(int k);
t_help				*create_help(int *start, int *end);
void                add_help(t_help *tmp, t_help *help);
char				*ft_copy_name(char *line, int i);
void                put_first_adjacency(char *line, t_graph **graph);
int                 ft_make_adjacency(char *line, t_graph **graph);
int		            ft_exit_checking(char **line, t_help **help);
int                 ft_exit_adjacency(t_graph **graph);
int                 ft_exit_adjacency_norm(char *c, char *line);
int                 ft_exit_adjacency_error(char *c, char *line, t_graph **graph);
int                 ft_exit_adjacency_error_two(char *line, t_graph **graph);
t_adjacency         *make_adjacency(int link_num);
int                 empty_queue(t_queue queue);
int                 size_queue(t_queue queue);
void                push_queue(t_queue *queue, int x);
int                 pop_queue(t_queue *queue);
t_queue             *init_queue(int size);
void		        main_alg(t_graph **graph);

#endif
