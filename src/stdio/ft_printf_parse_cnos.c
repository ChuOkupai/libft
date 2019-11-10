/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_cnos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 12:13:20 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 19:02:10 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_macros.h"
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
	if (f->precision >= 0 || FLAG(PF_MINUS))
		f->flags &= ~PF_ZERO;
	if (f->precision >= 0)
		f->dsize = MIN(f->precision, f->dsize);
	f->width = MAX(f->width - f->dsize, 0);
	if (!FLAG(PF_MINUS))
		pf_putpadding(f);
	while ((f->dsize -= pf_wclen(*s)) >= 0)
		pf_putwchar(f, *s++);
}

void		pf_parse_c(t_format *f)
{
	wchar_t c;

	if (*f->s == '%')
		c = '%';
	else if (FLAG(PF_L))
		c = va_arg(f->arg, wchar_t);
	else
		c = (char)va_arg(f->arg, int);
	if ((c < 0 && FLAG(PF_L)) || c > 0x10ffff)
	{
		f->err = -1;
		return ;
	}
	f->width = MAX(f->width - pf_wclen(c), 0);
	if (!FLAG(PF_MINUS))
		pf_putpadding(f);
	pf_putwchar(f, c);
	if (FLAG(PF_MINUS))
		pf_putpadding(f);
	f->s++;
}

void		pf_parse_n(t_format *f)
{
	int64_t *size;

	f->s++;
	if (!(size = va_arg(f->arg, int64_t*)))
		return ;
	if (FLAG(PF_LL))
		*size = f->size;
	else if (FLAG(PF_L))
		*size = f->size;
	else if (FLAG(PF_HH))
		*((char*)size) = (char)f->size;
	else if (FLAG(PF_H))
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
	if (!n && FLAG(PF_HASH) && f->precision)
		f->flags &= ~PF_HASH;
	if (f->precision >= 0 || FLAG(PF_MINUS))
		f->flags &= ~PF_ZERO;
	t = f->dsize + (FLAG(PF_HASH) != 0);
	f->precision = MAX(f->precision - t, 0);
	f->width = MAX(f->width - t - f->precision, 0);
	pf_print(f, s, "0");
}

void		pf_parse_s(t_format *f)
{
	const char *s;

	f->dsize = 0;
	if (FLAG(PF_L))
		pf_parse_ls(f);
	else
	{
		if (!(s = va_arg(f->arg, char*)))
			s = "(null)";
		f->dsize = ft_strlen(s);
		if (f->precision >= 0 || FLAG(PF_MINUS))
			f->flags &= ~PF_ZERO;
		if (f->precision >= 0)
			f->dsize = MIN(f->precision, f->dsize);
		f->width = MAX(f->width - f->dsize, 0);
		if (!FLAG(PF_MINUS))
			pf_putpadding(f);
		while (f->dsize--)
			pf_putchar(f, *s++);
	}
	if (FLAG(PF_MINUS))
		pf_putpadding(f);
	f->s++;
}
