/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdopen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 02:53:04 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/02 17:31:39 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_memory.h"
#include "ft_stdio_utils.h"

t_file	*ft_fdopen(int fd, const char *mode)
{
	t_file	*f;
	int		m;

	if (ft_parse_mode(mode, &m) || !(f = ft_calloc(1, sizeof(t_file))))
		return (NULL);
	f->fd = fd;
	f->mode = m;
	if (m & O_WRONLY)
		f->flags |= FT_FWRITE;
	ft_setbuffer(f, NULL, FT_FILE_BSIZE);
	return (f);
}
