/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:16:58 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/04 12:08:02 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_memory.h"
#include "ft_stdio_utils.h"

int		ft_parse_mode(const char *s, int *flags)
{
	int m;

	if (*s == 'r')
		m = O_RDONLY;
	else if (*s == 'w')
		m = O_WRONLY | O_CREAT | O_TRUNC;
	else if (*s == 'a')
		m = O_WRONLY | O_CREAT | O_APPEND;
	else
		return (errno = EINVAL);
	if (*(++s) == '+')
	{
		m = (m & (O_TRUNC | O_APPEND)) | O_RDWR;
		++s;
	}
	if (*s == 'x')
		m |= O_EXCL;
	*flags = m;
	return (0);
}

int		ft_check_buffer(t_file *f, t_fflag write)
{
	if (!f->buf && f->size && (f->flags & FT_FALLOC) &&
	!(f->buf = ft_calloc(1, f->size)))
		ft_setbuffer(f, f->safe_buf, FT_FILE_SAFEBSIZE);
	if (((f->flags ^ write) & FT_FWRITE))
	{
		if (!(f->mode & O_RDWR))
			return (f->flags |= FT_FERROR);
		if (!write && f->size - f->left)
			ft_fwrite_internal(f, f->buf, f->size - f->left);
		f->start = 0;
		f->left = write ? f->size : 0;
		if (write)
			f->flags |= FT_FWRITE;
		else
			f->flags &= ~FT_FWRITE;
	}
	return (0);
}

size_t	ft_fread_internal(t_file *f, void *ptr, size_t size)
{
	ssize_t n;

	if ((n = read(f->fd, ptr, size)) < 0)
	{
		f->flags |= FT_FERROR;
		n = 0;
	}
	else if (n)
		f->flags &= ~FT_FEOF;
	else if (size)
		f->flags |= FT_FEOF;
	if (f->buf == ptr)
	{
		f->start = 0;
		f->left = n;
	}
	return (n);
}

size_t	ft_fwrite_internal(t_file *f, const void *ptr, size_t size)
{
	ssize_t n;

	if ((n = write(f->fd, ptr, size)) < 0)
	{
		f->flags |= FT_FERROR;
		n = 0;
	}
	else if (size)
		f->flags &= ~FT_FEOF;
	if (f->buf == ptr)
	{
		f->start = 0;
		f->left = f->size;
	}
	return (n);
}
