/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 22:55:19 by hlarson           #+#    #+#             */
/*   Updated: 2018/12/16 16:42:21 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	size_t		len(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static	char		*viceverse(char *c, int n, size_t f)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	l;

	i = f;
	j = len(n) - 1 + f;
	k = len(n) - 1 + f;
	while (i <= (k / 2))
	{
		l = c[i];
		c[i] = c[j];
		c[j] = l;
		i++;
		j--;
	}
	return (c);
}

static	char		*ft_memory(int k, int n)
{
	char	*c;

	c = ft_strnew(k + len(n));
	return (c);
}

static	char		*ft_additoa(char *c, int n, size_t i)
{
	int		l;

	l = n;
	if (n == 0)
	{
		i = 0;
		c[i] = 0 + '0';
		c[i + 1] = '\0';
		return (c);
	}
	while (n)
	{
		c[i] = (n % 10) + '0';
		i++;
		n /= 10;
	}
	c[i] = '\0';
	return (c);
}

char				*ft_itoa(int n)
{
	char	*c;
	int		k;

	k = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		k = 1;
		n = n * (-1);
	}
	c = ft_memory(k, n);
	if (!c)
		return (NULL);
	c = ft_additoa(c, n, (size_t)k);
	if (k == 1)
	{
		c = viceverse(c, n, 1);
		c[0] = '-';
	}
	else
		c = viceverse(c, n, 0);
	return (c);
}
