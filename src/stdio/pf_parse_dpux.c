/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_dpux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 12:13:20 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/09 16:38:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static void	pf_set_fields(t_format *f, int hlen)
{
	if (f->precision >= 0 || FLAG(PF_MINUS))
		f->flags &= ~PF_ZERO;
	f->precision = MAX(f->precision - f->dsize, 0);
	hlen = f->dsize + f->precision + ((FLAG(PF_HASH)) ? hlen : 0);
	f->width = MAX(f->width - hlen, 0);
	if (FLAG(PF_ZERO))
	{
		f->precision = f->width;
		f->width = 0;
	}
}

void		pf_parse_d(t_format *f)
{
	const char	*h;
	const char	*s;
	int64_t		n;

	n = pf_parse_arg(f);
	s = pf_convert(f, ABS(n), 10, 1);
	if (n < 0)
		h = "-";
	else if (FLAG(PF_PLUS))
		h = "+";
	else
		h = FLAG(PF_SPACE) ? " " : 0;
	if (h)
		f->flags |= PF_HASH;
	else
		f->flags &= ~PF_HASH;
	pf_set_fields(f, 1);
	pf_print(f, s, h);
}

void		pf_parse_p(t_format *f)
{
	const char	*s;
	uint64_t	n;

	f->flags |= PF_LL;
	n = pf_parse_arg_unsigned(f);
	s = pf_convert(f, n, 16, 1);
	f->flags |= PF_HASH;
	pf_set_fields(f, 2);
	pf_print(f, s, "0x");
}

void		pf_parse_u(t_format *f)
{
	const char	*s;
	uint64_t	n;

	n = pf_parse_arg_unsigned(f);
	s = pf_convert(f, n, 10, 1);
	pf_set_fields(f, 0);
	pf_print(f, s, 0);
}

void		pf_parse_x(t_format *f)
{
	const char	*s;
	uint64_t	n;

	n = pf_parse_arg_unsigned(f);
	s = pf_convert(f, n, 16, *f->s == 'x');
	if (!n && FLAG(PF_HASH))
		f->flags &= ~PF_HASH;
	pf_set_fields(f, 2);
	pf_print(f, s, (*f->s == 'x') ? "0x" : "0X");
}
