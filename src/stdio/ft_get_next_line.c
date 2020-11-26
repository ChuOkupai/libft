/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:56:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 12:37:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_list.h"
#include "ft_memory.h"
#include "ft_string.h"
#include "ft_stdio_utils.h"

static int		compare_fd(const void *a, const void *b)
{
	return ((*(int*)a) - ((t_file*)b)->fd);
}

static t_file	*search_file(t_list **list, int fd)
{
	t_list *e;
	t_file *f;

	if ((e = ft_list_search(*list, &fd, &compare_fd)))
		return (e->content);
	if (!(f = ft_malloc(sizeof(t_file))) || !ft_list_push(list, ft_list_new(f)))
		return (ft_free(f));
	f->fd = fd;
	f->buf = NULL;
	return (f);
}

static char		*join_line(t_file *f, char *b)
{
	char *d;

	if (b && *b == '\n')
		*b++ = '\0';
	d = ft_strdup(f->buf ? f->buf : "");
	b = b && d ? ft_strdup(b) : NULL;
	ft_free(f->buf);
	f->buf = b;
	return (d);
}

static int		read_line(t_file *f, char **line)
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
		f->buf = ft_strjoin((f->buf ? f->buf : ""), buf);
		ft_free(b);
		if (!f->buf)
			return (-1);
		b = ft_strchrnul(f->buf, '\n');
	}
	return (n < 0 || !(*line = join_line(f, b)) ? -1 : n > 0);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_list	*l = NULL;
	t_file			*f;
	int				r;

	*line = NULL;
	if (fd < 0 || !(f = search_file(&l, fd)))
		r = -1;
	else if ((r = read_line(f, line)) < 1)
	{
		ft_free(f->buf);
		ft_free(ft_list_remove_one(&l, f));
	}
	return (r);
}
