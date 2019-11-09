/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 12:13:20 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/09 16:38:43 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static void	pf_set_fields(t_format *f)
{
	if (f->precision >= 0 || FLAG(PF_MINUS))
		f->flags &= ~PF_ZERO;
	if (f->precision >= 0)
		f->dsize = MIN(f->precision, f->dsize);
	f->width = MAX(f->width - f->dsize, 0);
}

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
	pf_set_fields(f);
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
		while (s[f->dsize])
			++f->dsize;
		pf_set_fields(f);
		if (!FLAG(PF_MINUS))
			pf_putpadding(f);
		while (f->dsize--)
			pf_putchar(f, *s++);
	}
	if (FLAG(PF_MINUS))
		pf_putpadding(f);
	f->s++;
}
