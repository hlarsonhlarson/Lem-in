/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:29:37 by hlarson           #+#    #+#             */
/*   Updated: 2018/12/10 21:16:12 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (haystack[i])
	{
		k = i;
		while ((haystack[i] == needle[j]) && haystack[i] && needle[j])
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)(haystack + i - j));
		i = k;
		j = 0;
		i++;
	}
	if (haystack[i] == needle[j])
		return ((char *)(haystack));
	return (NULL);
}
