/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:57:11 by hlarson           #+#    #+#             */
/*   Updated: 2018/12/12 19:19:38 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*c;

	i = 0;
	if ((s) && (f))
	{
		c = ft_strnew(ft_strlen(s));
		if (c)
		{
			while (s[i])
			{
				c[i] = f(i, s[i]);
				i++;
			}
			return (c);
		}
	}
	return (NULL);
}
