/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:54:25 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/21 14:27:11 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_format f;

	f.s = format;
	f.conv[PF_CONVERT_BUFF_SIZE] = '\0';
	f.fd = fd;
	f.use_str = 0;
	f.i = 0;
	f.err = 0;
	f.size = 0;
	pf_parse(&f, ap);
	if (f.i && !f.err)
		pf_flush_buffer(&f);
	return (f.err ? -1 : f.size);
}
