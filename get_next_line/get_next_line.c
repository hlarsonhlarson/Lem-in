/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlarson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 19:58:21 by hlarson           #+#    #+#             */
/*   Updated: 2019/07/31 18:12:52 by hlarson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static t_list		*get_file(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = (t_list *)malloc(sizeof(*tmp));
	tmp->content = ft_strnew(0);
	tmp->content_size = fd;
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

char				*rightft_strjoin(char *a, char *b)
{
	char	*c;
	char	*d;
	size_t	i;

	d = a;
	i = 0;
	c = ft_strnew(ft_strlen(d) + ft_strlen(b));
	if (!c)
		return (NULL);
	while (*d)
		c[i++] = *d++;
	while (*b)
		c[i++] = *b++;
	ft_strdel(&a);
	return (c);
}

int					copy(char **line, char *a, t_list *c, char *buf)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (a[i])
	{
		if (a[i] == '\n')
			break ;
		i++;
	}
	j = 0;
	*line = ft_strnew(i);
	while (j < i)
	{
		(*line)[j] = a[j];
		j++;
	}
	j = ft_strlen(a);
	if (ft_strchr(a + i, '\n'))
		(c->content) = rightft_strjoin((c->content), a + i + 1);
	i = (i == j) ? i - 1 : i;
	ft_strdel(&a);
	ft_strdel(&buf);
	return ((i < j) ? (int)i : -1);
}

char				*a_create(t_list *c)
{
	char	*a;

	a = ft_strnew(0);
	if (ft_strcmp((c->content), "\0") != 0)
	{
		a = rightft_strjoin(a, (c->content));
		free((c->content));
		c->content = ft_strnew(0);
	}
	return (a);
}

int					get_next_line(const int fd, char **line)
{
	char				*a;
	char				*buf;
	t_list				*c;
	static t_list		*list;
	int					ret;

	buf = (char *)malloc(BUFF_SIZE + 1);
	if (fd < 0 || (read(fd, buf, 0) < 0) || line == NULL)
		return (-1);
	c = get_file(&list, fd);
	a = a_create(c);
	if (!ft_strchr(a, '\n'))
	{
		while ((ret = read(fd, buf, BUFF_SIZE)))
		{
			buf[ret] = '\0';
			a = rightft_strjoin(a, buf);
			if (ft_strchr(buf, '\n'))
				break ;
		}
	}
	if (copy(line, a, c, buf) == -1 && ret < BUFF_SIZE)
		return (0);
	return (1);
}
