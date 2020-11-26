/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 02:53:04 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 12:37:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_memory.h"
#include "ft_stdio_utils.h"

t_file		*ft_fopen(const char *path, const char *mode)
{
	t_file	*f;
	int		m;

	if (ft_parse_mode(mode, &m) || !(f = ft_calloc(1, sizeof(t_file))))
		return (NULL);
	if ((f->fd = open(path, m, 0644)) < 0)
		return (ft_free(f));
	f->mode = m;
	f->flags = FT_FOPEN;
	if (m & O_WRONLY)
		f->flags |= FT_FWRITE;
	ft_setbuffer(f, NULL, FT_FILE_BSIZE);
	return (f);
}
