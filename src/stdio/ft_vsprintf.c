/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:36:07 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/23 14:36:29 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	t_format f;

	pf_init(&f, format, ap);
	f.pflags = PF_USE_STR;
	f.str = str;
	pf_parse(&f);
	if (f.i)
		pf_flush_buffer(&f);
	*f.str = '\0';
	return (f.pflags & PF_ERROR ? -1 : f.size);
}
