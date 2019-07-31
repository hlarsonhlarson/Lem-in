/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:48:55 by hlarson           #+#    #+#             */
/*   Updated: 2018/12/16 16:30:04 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	**ft_memory(char const *s, char c)
{
	size_t		i;
	size_t		k;
	char		**d;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[0] != c)
			k++;
		if ((s[i] == c) && (s[i + 1] != c))
			k++;
		i++;
	}
	d = (char **)malloc(sizeof(s) * (k));
	if (!d)
		return (NULL);
	return (d);
}

static char		**ft_memory1(char const *s, char c, char **d)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!d)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		if (s[i] != c)
		{
			while ((s[i] != c) && (s[i + 1] != '\0'))
			{
				k++;
				i++;
			}
			d[j] = ft_strnew(k);
			j++;
		}
		i++;
	}
	d[j] = ft_strnew(0);
	return (d);
}

static char		**ft_strsplit1(char const *s, char c, char **d)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = 0;
			while ((s[i] != c) && s[i])
			{
				d[j][k] = s[i];
				k++;
				i++;
			}
			j++;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	d[j] = NULL;
	return (d);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**d;

	if (!s)
		return (NULL);
	d = ft_memory1(s, c, ft_memory(s, c));
	if (!d)
		return (NULL);
	d = ft_strsplit1(s, c, d);
	return (d);
}
