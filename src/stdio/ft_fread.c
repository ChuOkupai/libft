/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 02:39:26 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/01 18:33:25 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_stdio_utils.h"

static size_t	copy(t_file *f, void *ptr, size_t nitems)
{
	if (!(nitems = f->left < nitems ? f->left : nitems))
		return (0);
	ft_memcpy(ptr, f->buf + f->start, nitems);
	f->start += nitems;
	f->left -= nitems;
	return (nitems);
}

size_t			ft_fread(void *ptr, size_t size, size_t nitems, t_file *f)
{
	size_t n;

	if (ft_check_buffer(f, 0))
		return (0);
	nitems *= size;
	n = copy(f, ptr, nitems);
	if ((nitems -= n) && nitems < f->size)
	{
		ft_fread_internal(f, f->buf, f->size);
		n += copy(f, ptr + n, nitems);
	}
	else if (!n)
		n = ft_fread_internal(f, ptr, nitems);
	return (size ? n / size : 0);
}
