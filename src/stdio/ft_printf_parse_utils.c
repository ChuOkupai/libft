/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:50:36 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 19:02:15 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/ft_printf.h"

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
		if (FLAG(PF_APOSTROPHE) && ++c == 4)
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

int64_t		pf_parse_arg(t_format *f)
{
	int64_t n;

	if (FLAG(PF_LL))
		n = va_arg(f->arg, int64_t);
	else if (FLAG(PF_L))
		n = va_arg(f->arg, int64_t);
	else
		n = va_arg(f->arg, int32_t);
	return (n);
}

uint64_t	pf_parse_arg_unsigned(t_format *f)
{
	uint64_t n;

	if (FLAG(PF_LL))
		n = va_arg(f->arg, uint64_t);
	else if (FLAG(PF_L))
		n = va_arg(f->arg, uint64_t);
	else
		n = va_arg(f->arg, uint32_t);
	return (n);
}
