/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:36:07 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/20 21:17:46 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vsprintf(char *str, const char *format, va_list ap)
{
	t_format f;

	f.s = format;
	f.conv[PF_CONVERT_BUFF_SIZE] = '\0';
	f.str = str;
	f.use_str = 1;
	f.i = 0;
	f.err = 0;
	f.size = 0;
	pf_parse(&f, ap);
	if (f.i && !f.err)
		pf_flush_buffer(&f);
	if (!f.err)
		f.str[f.size] = '\0';
	return (f.err ? -1 : f.size);
}
