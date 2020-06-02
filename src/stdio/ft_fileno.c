/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileno.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 02:11:52 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/01 16:23:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "ft_stdio_utils.h"

int	ft_fileno(t_file *stream)
{
	if (!stream)
	{
		errno = EBADF;
		return (-1);
	}
	return (stream->fd);
}
