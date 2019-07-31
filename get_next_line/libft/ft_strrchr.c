/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:10:56 by hlarson           #+#    #+#             */
/*   Updated: 2018/12/06 20:53:40 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	long	k;

	i = 0;
	k = -1;
	while (s[i])
	{
		if (s[i] == c)
			k = i;
		i++;
	}
	if (s[i] == c)
		k = i;
	if (k == -1)
		return (NULL);
	return ((char *)(s + k));
}
