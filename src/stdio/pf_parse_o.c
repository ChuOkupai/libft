/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_o.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 12:13:20 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/09 16:39:04 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void	pf_parse_o(t_format *f)
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
