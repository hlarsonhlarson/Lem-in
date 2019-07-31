/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:52:39 by hlarson           #+#    #+#             */
/*   Updated: 2018/12/12 19:16:23 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*c;
	size_t	i;

	i = 0;
	if ((s) && (f))
	{
		c = ft_strnew(ft_strlen(s));
		if (c)
		{
			while (s[i])
			{
				c[i] = f(s[i]);
				i++;
			}
			return (c);
		}
	}
	return (NULL);
}
