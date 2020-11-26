/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setbuffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 02:42:08 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 12:37:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_memory.h"
#include "ft_stdio_utils.h"

void	ft_setbuffer(t_file *f, char *buf, size_t size)
{
	if (f->buf)
		ft_bzero(f->buf, f->size);
	if (f->flags & FT_FALLOC)
	{
		ft_free(f->buf);
		f->flags &= ~FT_FALLOC;
	}
	if (f->mode & O_RDWR)
		size = size > 0;
	f->buf = size ? buf : NULL;
	f->size = size;
	f->start = 0;
	f->left = f->flags & FT_FWRITE ? f->size : 0;
	if (!buf)
		f->flags |= FT_FALLOC;
}
