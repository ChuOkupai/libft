/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 02:39:52 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/01 23:28:12 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_stdio_utils.h"

static size_t	copy(t_file *f, const void *ptr, size_t nitems)
{
	ft_memcpy(f->buf + f->start, ptr, nitems);
	f->start += nitems;
	if (!(f->left -= nitems))
		ft_fwrite_internal(f, f->buf, f->size);
	return (nitems);
}

size_t			ft_fwrite(const void *ptr, size_t size, size_t nitems,
				t_file *f)
{
	size_t n;

	if (ft_check_buffer(f, FT_FWRITE))
		return (0);
	nitems *= size;
	if (nitems <= f->left)
		n = copy(f, ptr, nitems);
	else
	{
		if (f->size - f->left)
			ft_fwrite_internal(f, f->buf, f->size - f->left);
		n = ft_fwrite_internal(f, ptr, nitems);
	}
	return (size ? n / size : 0);
}
