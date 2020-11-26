/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdelim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:56:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 12:37:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_memory.h"
#include "ft_stdio_utils.h"
#include "ft_type.h"

static char		*join_line(t_file *f, char *line, size_t n1, size_t n2)
{
	char *s;

	if (!n2)
		return (line);
	if (!(s = ft_malloc((n1 + n2 + 1) * sizeof(char))))
		return (ft_free(line));
	ft_memcpy((t_u8 *)ft_memcpy(s, line, n1) + n1, f->buf, n2);
	s[n1 + n2] = '\0';
	free(line);
	return (s);
}

static size_t	read_line(char **line, int delim, t_file *f)
{
	size_t	size;
	size_t	n;
	char	*p;

	size = f->left;
	if (!(*line = ft_memdup(f->buf + f->start, size, size + 1, true)))
		return (0);
	while (ft_fread_internal(f, f->buf, f->size))
	{
		p = ft_memchr(f->buf, delim, f->left);
		n = p ? (size_t)(p - f->buf) : f->left;
		if (!(*line = join_line(f, *line, size, n)))
			break ;
		size += n;
		n += p != NULL;
		f->start += n;
		f->left -= n;
		if (p || !line)
			break ;
	}
	return (size);
}

ssize_t			ft_getdelim(char **line, int delim, t_file *f)
{
	ssize_t	size;
	char	*p;

	*line = NULL;
	if (ft_check_buffer(f, 0))
		return (FT_EOF);
	if (!f->size)
		return (FT_EOF);
	else if ((p = ft_memchr(f->buf + f->start, delim, f->left)))
	{
		size = p - f->buf - f->start;
		*line = ft_memdup(f->buf + f->start, size, size + 1, true);
		f->start += size + 1;
		f->left -= size + 1;
	}
	else
		size = read_line(line, delim, f);
	if (f->flags & FT_FERROR)
		*line = ft_free(*line);
	return ((f->flags & FT_FEOF) || !*line ? FT_EOF : size);
}
