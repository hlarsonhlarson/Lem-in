/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:34:33 by hlarson           #+#    #+#             */
/*   Updated: 2018/12/16 17:01:25 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*c;

	c = (t_list *)malloc(sizeof(t_list));
	if (!c)
		return (NULL);
	if (content == NULL)
	{
		c->content = NULL;
		c->content_size = 0;
	}
	else
	{
		c->content = malloc(sizeof(content_size));
		if (!c->content)
			return (NULL);
		ft_memcpy(c->content, content, content_size);
		c->content_size = content_size;
	}
	c->next = NULL;
	return (c);
}
