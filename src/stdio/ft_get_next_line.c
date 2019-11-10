/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:56:36 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:37:02 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft_list.h"
#include "libft_string.h"
#include "utils/ft_get_next_line.h"

static int		ft_filecmp(const void *a, const void *b)
{
	return ((*(int*)a) - ((t_file*)b)->fd);
}

static t_list	*ft_search_file(t_list **l, int fd)
{
	t_file *f;
	t_list *e;

	e = ft_list_extract(l, &fd, &ft_filecmp);
	if (!e && (f = malloc(sizeof(t_file))))
	{
		f->buf = NULL;
		f->fd = fd;
		if (!(e = ft_list_new(f)))
			free(f);
	}
	return (e);
}

static char		*ft_join_line(t_file *f, char *b)
{
	char *d;

	if (b && *b == '\n')
		*b++ = '\0';
	d = ft_strdup(f->buf ? f->buf : "");
	b = b ? ft_strdup(b) : NULL;
	if (f->buf)
		free(f->buf);
	f->buf = b;
	return (d);
}

static int		ft_read_line(t_file *f, char **line)
{
	char	buf[GL_BUFF_SIZE + 1];
	char	*b;
	int		n;

	n = 1;
	b = f->buf ? ft_strchrnul(f->buf, '\n') : NULL;
	while ((!b || !*b) && (n = read(f->fd, buf, GL_BUFF_SIZE)) > 0)
	{
		buf[n] = '\0';
		b = f->buf;
		f->buf = ft_strjoin((f->buf ? f->buf : ""), buf);
		if (b)
			free(b);
		if (!f->buf && (n = -1))
			break ;
		b = ft_strchrnul(f->buf, '\n');
	}
	if (n < 0 || !(*line = ft_join_line(f, b)))
		return (-1);
	return (n > 0);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_list	*l = NULL;
	t_list			*e;
	int				r;

	*line = NULL;
	if (fd < 0 || !(e = ft_search_file(&l, fd)))
		r = -1;
	else if ((r = ft_read_line(e->content, line)) < 1)
	{
		if (((t_file*)(e->content))->buf)
			free(((t_file*)(e->content))->buf);
		free(e->content);
		free(e);
	}
	else
		ft_list_push(&l, e);
	return (r);
}