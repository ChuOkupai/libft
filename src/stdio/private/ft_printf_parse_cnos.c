/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_cnos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 12:13:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/27 11:58:45 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf.h"

static void	pf_parse_ls(t_format *f, wchar_t *s)
{
	int i;

	if (!s)
		s = L"(null)";
	i = -1;
	while (s[++i] != L'\0' && (f->precision < 0
		|| (f->precision >= 0 && f->dsize + pf_wclen(s[i]) <= f->precision)))
		f->dsize += pf_wclen(s[i]);
	if (f->precision >= 0 || (f->flags & PF_MINUS))
		f->flags &= ~PF_ZERO;
	if (f->precision >= 0)
		f->dsize = ((f->precision < f->dsize) ? f->precision : f->dsize);
	if ((f->width = f->width - f->dsize) < 0)
		f->width = 0;
	if (!(f->flags & PF_MINUS))
		pf_putpadding(f);
	while ((f->dsize -= pf_wclen(*s)) >= 0)
		pf_putwchar(f, *s++);
}

void		pf_parse_c(t_format *f)
{
	wchar_t c;

	if (*f->s == '%')
		c = '%';
	else if ((f->flags & PF_L))
		c = va_arg(f->l, wchar_t);
	else
		c = (char)va_arg(f->l, int);
	f->s++;
	if ((c < 0 && (f->flags & PF_L)) || c > 0x10ffff)
	{
		f->pflags |= PF_ERROR;
		return ;
	}
	if ((f->width = f->width - pf_wclen(c)) < 0)
		f->width = 0;
	if (!(f->flags & PF_MINUS))
		pf_putpadding(f);
	pf_putwchar(f, c);
	if ((f->flags & PF_MINUS))
		pf_putpadding(f);
}

void		pf_parse_n(t_format *f, int64_t *size)
{
	f->s++;
	if (!size)
		return ;
	if ((f->flags & PF_LL))
		*((long long*)size) = f->size;
	else if ((f->flags & PF_L))
		*((long*)size) = f->size;
	else if ((f->flags & PF_HH))
		*((char*)size) = (char)f->size;
	else if ((f->flags & PF_H))
		*((short*)size) = (short)f->size;
	else
		*((int*)size) = f->size;
}

void		pf_parse_o(t_format *f, t_u128 n)
{
	const char	*s;
	int			t;

	s = pf_convert(f, n, 8, 1);
	if (!n && (f->flags & PF_HASH) && f->precision)
		f->flags &= ~PF_HASH;
	if (f->precision >= 0 || (f->flags & PF_MINUS))
		f->flags &= ~PF_ZERO;
	t = f->dsize + ((f->flags & PF_HASH) != 0);
	if ((f->precision = f->precision - t) < 0)
		f->precision = 0;
	if ((f->width = f->width - t - f->precision) < 0)
		f->width = 0;
	pf_print(f, s, "0");
}

void		pf_parse_s(t_format *f, char *s)
{
	f->dsize = 0;
	if ((f->flags & PF_L))
		pf_parse_ls(f, (wchar_t*)s);
	else
	{
		if (!s)
			s = "(null)";
		f->dsize = ft_strlen(s);
		if (f->precision >= 0 || (f->flags & PF_MINUS))
			f->flags &= ~PF_ZERO;
		if (f->precision >= 0)
			f->dsize = ((f->precision < f->dsize) ? f->precision : f->dsize);
		if ((f->width = f->width - f->dsize) < 0)
			f->width = 0;
		if (!(f->flags & PF_MINUS))
			pf_putpadding(f);
		while (f->dsize--)
			pf_putchar(f, *s++);
	}
	if ((f->flags & PF_MINUS))
		pf_putpadding(f);
	f->s++;
}
