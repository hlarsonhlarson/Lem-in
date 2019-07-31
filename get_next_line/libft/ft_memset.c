/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:29:34 by hlarson           #+#    #+#             */
/*   Updated: 2018/11/30 17:59:36 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*b;

	b = (unsigned char *)s;
	i = 0;
	while (i != n)
	{
		b[i] = c;
		i++;
	}
	return (b);
}
