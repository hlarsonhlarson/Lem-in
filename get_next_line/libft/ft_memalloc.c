/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:49:03 by hlarson           #+#    #+#             */
/*   Updated: 2018/12/12 18:49:40 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void			*str;

	str = (void *)malloc(size);
	if (str)
		ft_bzero(str, size);
	else
		return (NULL);
	return ((void *)(str));
}
