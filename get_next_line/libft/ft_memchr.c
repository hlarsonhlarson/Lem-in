/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:49:05 by hlarson           #+#    #+#             */
/*   Updated: 2018/11/30 18:53:36 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*a;
	char		b;
	size_t		i;

	a = (char *)s;
	b = (char)c;
	i = 0;
	while (i != n)
	{
		if (a[i] == b)
			return (a + i);
		i++;
	}
	return (NULL);
}
