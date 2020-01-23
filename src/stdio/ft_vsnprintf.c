/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:10:50 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/23 14:36:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vsnprintf(char *str, size_t n, const char *format, va_list ap)
{
	t_format f;

	pf_init(&f, format, ap);
	f.pflags = PF_USE_STR | PF_USE_LEFT;
	f.str = str;
	f.left = n;
	pf_parse(&f);
	if (f.i)
		pf_flush_buffer(&f);
	if (f.left > 0)
		*f.str = '\0';
	return (f.pflags & PF_ERROR ? -1 : f.size);
}
