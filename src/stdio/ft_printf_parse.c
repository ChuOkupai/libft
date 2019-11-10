/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 12:13:20 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 19:02:19 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ctype.h"
#include "utils/ft_printf.h"

static int	pf_parse_field(t_format *f)
{
	int		precision;
	long	n;

	n = 0;
	if ((precision = *f->s == '.'))
		f->s++;
	if (*f->s == '*' && *f->s++)
		n = va_arg(f->arg, int);
	else
		while (ft_isdigit(*f->s))
			n = n * 10 + *f->s++ - '0';
	if (n >= 0)
		return (n);
	n = (precision) ? -1 : -n;
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
		f->flags |= (FLAG(PF_L)) ? PF_LL : PF_L;
	else if (*f->s == 'h')
		f->flags |= (FLAG(PF_H)) ? PF_HH : PF_H;
	else
		return (0);
	f->s++;
	return (1);
}

static int	pf_parse_flags(t_format *f)
{
	f->s++;
	f->flags = 0;
	f->precision = -1;
	f->width = 0;
	while (*f->s)
		if (*f->s == '*' || (*f->s >= '1' && *f->s <= '9'))
			f->width = pf_parse_field(f);
		else if (*f->s == '.')
			f->precision = pf_parse_field(f);
		else if (!pf_parse_subflags(f))
			break ;
	return (1);
}

void		pf_parse(t_format *f)
{
	while (*f->s && !f->err)
		if (*f->s != '%')
			pf_putchar(f, *f->s++);
		else if ((pf_parse_flags(f) && *f->s == '%') || *f->s == 'c')
			pf_parse_c(f);
		else if (*f->s == 'd' || *f->s == 'i')
			pf_parse_d(f);
		else if (*f->s == 'u')
			pf_parse_u(f);
		else if (*f->s == 's')
			pf_parse_s(f);
		else if (*f->s == 'x' || *f->s == 'X')
			pf_parse_x(f);
		else if (*f->s == 'o')
			pf_parse_o(f);
		else if (*f->s == 'p')
			pf_parse_p(f);
		else if (*f->s == 'n')
			pf_parse_n(f);
}
