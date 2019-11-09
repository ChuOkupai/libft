/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:50:36 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/09 16:38:36 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

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
