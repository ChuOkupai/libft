/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 04:03:35 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 12:37:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_memory.h"
#include "ft_stdio_utils.h"

int	ft_fclose(t_file *stream)
{
	int v;

	v = stream->flags & FT_FWRITE ? ft_fflush(stream) : 0;
	if ((stream->flags & FT_FOPEN) && close(stream->fd) < 0)
		v = FT_EOF;
	if (stream->flags & FT_FALLOC)
		ft_free(stream->buf);
	free(stream);
	return (v);
}
