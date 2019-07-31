/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:09:48 by hlarson           #+#    #+#             */
/*   Updated: 2018/12/16 16:50:35 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*c;

	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		c = (char *)malloc(sizeof(c) * (i + 1));
		if (!c)
			return (0);
		i = 0;
		while (*s1)
			c[i++] = *s1++;
		while (*s2)
			c[i++] = *s2++;
		c[i] = '\0';
		return (c);
	}
	return (NULL);
}
