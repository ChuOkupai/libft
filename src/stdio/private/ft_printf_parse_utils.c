/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:50:36 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/27 12:05:44 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_convert(t_format *f, t_u128 n, int base, int lower)
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

void	pf_init(t_format *f, const char *format, va_list l)
{
	f->conv[PF_CONVERT_BUFF_SIZE] = '\0';
	f->i = 0;
	f->s = format;
	va_copy(f->l, l);
	f->pflags = 0;
	f->size = 0;
}

t_s128	pf_va_arg(t_flag f, va_list l)
{
	t_s128 n;

	if (f & PF_LL)
		n = va_arg(l, t_s128);
	else if (f & PF_L)
		n = va_arg(l, t_s64);
	else if (f & PF_HH)
		n = (t_s8)va_arg(l, t_s32);
	else if (f & PF_H)
		n = (t_s16)va_arg(l, t_s32);
	else
		n = va_arg(l, t_s32);
	return (n);
}

t_u128	pf_va_arg_unsigned(t_flag f, va_list l)
{
	t_u128 n;

	if (f & PF_LL)
		n = va_arg(l, t_u128);
	else if (f & PF_L)
		n = va_arg(l, t_u64);
	else if (f & PF_HH)
		n = (t_u8)va_arg(l, t_u32);
	else if (f & PF_H)
		n = (t_u16)va_arg(l, t_u32);
	else
		n = va_arg(l, t_u32);
	return (n);
}
