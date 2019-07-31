/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:52:05 by hlarson           #+#    #+#             */
/*   Updated: 2018/12/06 17:41:32 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned char		*s;
	unsigned char		l;

	i = 0;
	l = (unsigned)c;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i != n)
	{
		d[i] = s[i];
		if (s[i] == l)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
