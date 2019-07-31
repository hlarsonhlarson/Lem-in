/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:56:24 by hlarson           #+#    #+#             */
/*   Updated: 2018/12/16 17:28:22 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*c;
	t_list	*start;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	c = f(lst);
	new = ft_lstnew(c->content, c->content_size);
	if (!new)
		return (NULL);
	start = new;
	lst = lst->next;
	while (lst)
	{
		c = f(lst);
		new->next = ft_lstnew(c->content, c->content_size);
		if (!new->next)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
