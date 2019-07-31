/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:51:18 by hlarson           #+#    #+#             */
/*   Updated: 2018/12/16 18:49:45 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (n == 0)
		return (NULL);
	while ((big[i]) && (i != n - 1))
	{
		k = i;
		while ((big[i] == little[j]) && little[j] && (i != n))
		{
			i++;
			j++;
		}
		if (little[j] == '\0')
			return (char *)((big + (i - j)));
		i = k;
		i++;
		j = 0;
	}
	if (big[i] == little[j])
		return (char *)((big + (i - j)));
	return (NULL);
}
