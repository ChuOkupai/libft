/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:23:54 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/09 17:01:00 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	t_format f;

	f.s = format;
	f.conv[PF_CONVERT_BUFF_SIZE] = '\0';
	f.fd = fd;
	f.i = 0;
	f.err = 0;
	f.size = 0;
	va_start(f.arg, format);
	pf_parse(&f);
	va_end(f.arg);
	if (f.i && !f.err)
		pf_flush_buffer(&f);
	return ((f.err) ? -1 : f.size);
}
