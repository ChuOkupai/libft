/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 02:53:04 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/01 21:01:12 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_memory.h"
#include "ft_stdio_utils.h"

static int	parse_mode(const char *s, int *flags)
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

t_file		*ft_fopen(const char *path, const char *s)
{
	t_file	*f;
	int		m;

	if (parse_mode(s, &m) || !(f = ft_calloc(1, sizeof(t_file))))
		return (NULL);
	if ((f->fd = open(path, m, 0644)) < 0)
		return (ft_memdel(f));
	f->mode = m;
	f->flags = FT_FOPEN;
	if (m & O_WRONLY)
		f->flags |= FT_FWRITE;
	ft_setbuffer(f, NULL, FT_FILE_BSIZE);
	return (f);
}
