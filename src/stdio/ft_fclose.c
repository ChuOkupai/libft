/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 04:03:35 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/26 05:13:10 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_memory.h"
#include "ft_stdio.h"

int	ft_fclose(t_file *stream)
{
	int v;

	// Add ft_fflush
	v = close(stream->fd) ? EOF : 0;
	ft_memdel(stream->buf);
	free(stream);
	return (v);
}
