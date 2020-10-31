/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_dpux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 12:13:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/27 11:58:45 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_set_fields(t_format *f, int hlen)
{
	if (f->precision >= 0 || (f->flags & PF_MINUS))
		f->flags &= ~PF_ZERO;
	if ((f->precision = f->precision - f->dsize) < 0)
		f->precision = 0;
	hlen = f->dsize + f->precision + (((f->flags & PF_HASH)) ? hlen : 0);
	if ((f->width = f->width - hlen) < 0)
		f->width = 0;
	if ((f->flags & PF_ZERO))
	{
		f->precision = f->width;
		f->width = 0;
	}
}

void		pf_parse_d(t_format *f, int64_t n)
{
	const char	*h;
	const char	*s;

	s = pf_convert(f, (n < 0 ? -n : n), 10, 1);
	if (n < 0)
		h = "-";
	else if ((f->flags & PF_PLUS))
		h = "+";
	else
		h = (f->flags & PF_SPACE) ? " " : 0;
	if (h)
		f->flags |= PF_HASH;
	else
		f->flags &= ~PF_HASH;
	pf_set_fields(f, 1);
	pf_print(f, s, h);
}

void		pf_parse_p(t_format *f, t_u128 n)
{
	const char *s;

	f->flags |= PF_LL;
	s = pf_convert(f, n, 16, 1);
	f->flags |= PF_HASH;
	pf_set_fields(f, 2);
	pf_print(f, s, "0x");
}

void		pf_parse_u(t_format *f, t_u128 n)
{
	const char *s;

	s = pf_convert(f, n, 10, 1);
	pf_set_fields(f, 0);
	pf_print(f, s, 0);
}

void		pf_parse_x(t_format *f, t_u128 n)
{
	const char *s;

	s = pf_convert(f, n, 16, *f->s == 'x');
	if (!n && (f->flags & PF_HASH))
		f->flags &= ~PF_HASH;
	pf_set_fields(f, 2);
	pf_print(f, s, (*f->s == 'x') ? "0x" : "0X");
}
