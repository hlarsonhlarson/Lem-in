/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:05:37 by hlarson           #+#    #+#             */
/*   Updated: 2018/12/16 16:43:47 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*c;

	i = 0;
	c = ft_strnew(len);
	if ((c) && (s))
	{
		while ((i != len) && (s[i]))
		{
			c[i] = s[i + start];
			i++;
		}
		return (c);
	}
	return (NULL);
}
