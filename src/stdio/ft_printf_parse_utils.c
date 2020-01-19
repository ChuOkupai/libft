/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:50:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/19 21:09:05 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*pf_convert(t_format *f, uint64_t n, int base, int lower)
{
	char	*d;
	int		i;
	int		c;

	if (lower)
		lower = 32;
	d = f->conv + PF_CONVERT_BUFF_SIZE;
	c = 0;
	if (!n && f->precision)
		*--d = '0';
	while (n)
	{
		if ((f->flags & PF_APOSTROPHE) && ++c == 4)
		{
			*--d = ',';
			c = 1;
		}
		i = n % base;
		*--d = i + ((i < 10) ? '0' : lower + 'A' - 10);
		n /= base;
	}
	f->dsize = f->conv + PF_CONVERT_BUFF_SIZE - d;
	return (d);
}

int64_t		pf_va_arg(t_flag f, va_list l)
{
	int64_t n;

	if (f & PF_LL)
		n = va_arg(l, int64_t);
	else if (f & PF_L)
		n = va_arg(l, int64_t);
	else
		n = va_arg(l, int32_t);
	return (n);
}

uint64_t	pf_va_arg_unsigned(t_flag f, va_list l)
{
	uint64_t n;

	if (f & PF_LL)
		n = va_arg(l, uint64_t);
	else if (f & PF_L)
		n = va_arg(l, uint64_t);
	else
		n = va_arg(l, uint32_t);
	return (n);
}
