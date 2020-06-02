/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fflush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 02:09:27 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/01 16:46:45 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include "ft_stdio_utils.h"

int	ft_fflush(t_file *f)
{
	if (f->mode & O_RDONLY)
	{
		errno = EBADF;
		return (FT_EOF);
	}
	else if (f->flags & FT_FWRITE && f->size - f->left)
		return (ft_fwrite_internal(f, f->buf, f->size - f->left) ? 0 : FT_EOF);
	return (0);
}
