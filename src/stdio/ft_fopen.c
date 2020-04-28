/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 02:53:04 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/28 02:02:08 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_memory.h"
#include "ft_stdio.h"

static int	parse_mode(const char *s, int *mode)
{
	if (*s == 'r')
		*mode = O_RDONLY;
	else if (*s == 'w')
		*mode = O_WRONLY | O_CREAT | O_TRUNC;
	else if (*s == 'a')
		*mode = O_WRONLY | O_CREAT | O_APPEND;
	else
		return (errno = EINVAL);
	if (*(++s) == '+')
	{
		*mode &= ~(O_RDONLY | O_WRONLY);
		*mode |= O_RDWR;
		++s;
	}
	if (*s == 'x')
	{
		*mode |= O_EXCL;
		while (*++s == 'x');
	}
	return (0);
}

t_file		*ft_fopen(const char *path, const char *mode)
{
	t_file *f;

	if (!(f = malloc(sizeof(t_file))))
		return (NULL);
	ft_bzero(f, sizeof(t_file));
	f->bsize = FT_FILE_BUFSIZE;
	f->bmode = IO_BUFMODE_FULL;
	if (parse_mode(mode, &f->mode) || (f->fd = open(path, f->mode, 0644)) < 0)
		return (ft_memdel(f));
	return (f);
}
