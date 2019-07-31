/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:59:00 by hlarson           #+#    #+#             */
/*   Updated: 2018/11/30 17:58:37 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	char				*s;
	char				*d;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	while (i != n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
