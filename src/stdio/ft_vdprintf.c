/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 20:54:25 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/23 14:36:25 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_format f;

	pf_init(&f, format, ap);
	f.fd = fd;
	pf_parse(&f);
	if (f.i)
		pf_flush_buffer(&f);
	return (f.pflags & PF_ERROR ? -1 : f.size);
}
