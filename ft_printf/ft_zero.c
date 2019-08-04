/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:38:56 by hlarson           #+#    #+#             */
/*   Updated: 2019/03/26 14:21:05 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_zero(void *s, size_t len)
{
	size_t				i;
	unsigned char		*b;

	i = 0;
	b = (unsigned char *)s;
	while (i != len - 1)
	{
		b[i] = '0';
		i++;
	}
	b[i] = '\0';
}