/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 12:13:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/19 21:07:48 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ctype.h"
#include "ft_printf.h"

static int	pf_parse_field(t_format *f, va_list l)
{
	int		precision;
	long	n;

	n = 0;
	if ((precision = *f->s == '.'))
		f->s++;
	if (*f->s == '*' && *f->s++)
		n = va_arg(l, int);
	else
		while (ft_isdigit(*f->s))
			n = n * 10 + *f->s++ - '0';
	if (n >= 0)
		return (n);
	n = precision ? -1 : -n;
	if (!precision)
		f->flags |= PF_MINUS;
	return (n);
}

static int	pf_parse_subflags(t_format *f)
{
	if (*f->s == '-')
		f->flags |= PF_MINUS;
	else if (*f->s == '0')
		f->flags |= PF_ZERO;
	else if (*f->s == '#')
		f->flags |= PF_HASH;
	else if (*f->s == '\'')
		f->flags |= PF_APOSTROPHE;
	else if (*f->s == ' ')
		f->flags |= PF_SPACE;
	else if (*f->s == '+')
		f->flags |= PF_PLUS;
	else if (*f->s == 'l')
		f->flags |= (f->flags & PF_L) ? PF_LL : PF_L;
	else if (*f->s == 'h')
		f->flags |= (f->flags & PF_H) ? PF_HH : PF_H;
	else
		return (0);
	f->s++;
	return (1);
}

static int	pf_parse_flags(t_format *f, va_list l)
{
	f->s++;
	f->flags = 0;
	f->precision = -1;
	f->width = 0;
	while (*f->s)
		if (*f->s == '*' || (*f->s >= '1' && *f->s <= '9'))
			f->width = pf_parse_field(f, l);
		else if (*f->s == '.')
			f->precision = pf_parse_field(f, l);
		else if (!pf_parse_subflags(f))
			break ;
	return (1);
}

void		pf_parse(t_format *f, va_list l)
{
	while (*f->s && !f->err)
		if (*f->s != '%')
			pf_putchar(f, *f->s++);
		else if ((pf_parse_flags(f, l) && *f->s == '%') || *f->s == 'c')
			pf_parse_c(f, l);
		else if (*f->s == 'd' || *f->s == 'i')
			pf_parse_d(f, pf_va_arg(f->flags, l));
		else if (*f->s == 'u')
			pf_parse_u(f, pf_va_arg_unsigned(f->flags, l));
		else if (*f->s == 's')
			pf_parse_s(f, va_arg(l, char*));
		else if (*f->s == 'x' || *f->s == 'X')
			pf_parse_x(f, pf_va_arg_unsigned(f->flags, l));
		else if (*f->s == 'o')
			pf_parse_o(f, pf_va_arg_unsigned(f->flags, l));
		else if (*f->s == 'p')
			pf_parse_p(f, (uint64_t)va_arg(l, void*));
		else if (*f->s == 'n')
			pf_parse_n(f, va_arg(l, int64_t*));
}
