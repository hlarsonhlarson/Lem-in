/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:13:39 by hlarson           #+#    #+#             */
/*   Updated: 2018/12/16 16:51:40 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	size_t	firstspace(char const *s)
{
	size_t	i;

	i = 0;
	while (((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')) && s[i])
		i++;
	return (i);
}

static	size_t	secondspace(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	i--;
	while (((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')) && (i != 0))
		i--;
	return (i + 1);
}

char			*ft_strtrim(char const *s)
{
	char	*c;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s)
	{
		i = firstspace(s);
		j = secondspace(s);
		if (j <= i)
			return (ft_strnew(0));
		c = ft_strnew((secondspace(s) - firstspace(s)));
		if (!c)
			return (NULL);
		k = 0;
		while (i != j)
		{
			c[k] = s[i];
			i++;
			k++;
		}
		c[k] = '\0';
		return (c);
	}
	return (NULL);
}
