/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:56:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/01 23:57:12 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_list.h"
#include "ft_memory.h"
#include "ft_string.h"
#include "ft_stdio_utils.h"

static int	ft_filecmp(const void *a, const void *b)
{
	return ((*(int*)a) - ((t_file*)b)->fd);
}

static int	ft_file_set(t_list **l, int fd)
{
	t_list *e;
	t_file *f;

	if ((e = ft_list_extract(l, &fd, &ft_filecmp)))
		return (ft_list_push(l, e) != NULL);
	if (!(f = malloc(sizeof(t_file))) || !ft_list_push(l, ft_list_new(f)))
		return (ft_memdel(f) != NULL);
	f->fd = fd;
	f->buf = NULL;
	return (1);
}

static char	*ft_join_line(t_file *f, char *b)
{
	char *d;

	if (b && *b == '\n')
		*b++ = '\0';
	d = ft_strdup(f->buf ? f->buf : "");
	b = b && d ? ft_strdup(b) : NULL;
	ft_memdel(f->buf);
	f->buf = b;
	return (d);
}

static int	ft_read_line(t_file *f, char **line)
{
	char	buf[FT_GNL_BSIZE + 1];
	char	*b;
	int		n;

	n = 1;
	b = f->buf ? ft_strchrnul(f->buf, '\n') : NULL;
	while ((!b || !*b) && (n = read(f->fd, buf, FT_GNL_BSIZE)) > 0)
	{
		buf[n] = '\0';
		b = f->buf;
		f->buf = ft_strjoin(f->buf, buf);
		ft_memdel(b);
		if (!f->buf)
			return (-1);
		b = ft_strchrnul(f->buf, '\n');
	}
	return (n < 0 || !(*line = ft_join_line(f, b)) ? -1 : n > 0);
}

int			ft_get_next_line(const int fd, char **line)
{
	static t_list	*l = NULL;
	int				r;

	*line = NULL;
	if (fd < 0 || !ft_file_set(&l, fd))
		r = -1;
	else if ((r = ft_read_line(l->content, line)) < 1)
	{
		ft_memdel(((t_file*)(l->content))->buf);
		ft_list_pop(&l, &free);
	}
	return (r);
}
