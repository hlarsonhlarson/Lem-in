/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 17:57:01 by hlarson           #+#    #+#             */
/*   Updated: 2019/07/31 18:07:19 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct		s_graph
{
	char			*name;
	struct s_graph	*connect;
	//maybe better make this in additional array
	int				available;
}					t_graph;
