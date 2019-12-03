/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_cnos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 12:13:20 by asoursou          #+#    #+#             */
/*   Updated: 2019/12/03 12:33:02 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"
#include "utils/ft_printf.h"

static void	pf_parse_ls(t_format *f)
{
	wchar_t	*s;
	int		i;

	if (!(s = va_arg(f->arg, wchar_t*)))
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
		c = va_arg(f->arg, wchar_t);
	else
		c = (char)va_arg(f->arg, int);
	if ((c < 0 && (f->flags & PF_L)) || c > 0x10ffff)
	{
		f->err = -1;
		return ;
	}
	if ((f->width = f->width - pf_wclen(c)) < 0)
		f->width = 0;
	if (!(f->flags & PF_MINUS))
		pf_putpadding(f);
	pf_putwchar(f, c);
	if ((f->flags & PF_MINUS))
		pf_putpadding(f);
	f->s++;
}

void		pf_parse_n(t_format *f)
{
	int64_t *size;

	f->s++;
	if (!(size = va_arg(f->arg, int64_t*)))
		return ;
	if ((f->flags & PF_LL))
		*size = f->size;
	else if ((f->flags & PF_L))
		*size = f->size;
	else if ((f->flags & PF_HH))
		*((char*)size) = (char)f->size;
	else if ((f->flags & PF_H))
		*((short*)size) = (short)f->size;
	else
		*((int*)size) = f->size;
}

void		pf_parse_o(t_format *f)
{
	const char	*s;
	uint64_t	n;
	int			t;

	n = pf_parse_arg_unsigned(f);
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

void		pf_parse_s(t_format *f)
{
	const char *s;

	f->dsize = 0;
	if ((f->flags & PF_L))
		pf_parse_ls(f);
	else
	{
		if (!(s = va_arg(f->arg, char*)))
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
