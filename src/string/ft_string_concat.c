/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_concat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:33:52 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/31 17:23:55 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_string.h"

int	ft_string_concat(t_string *s, ...)
{
	va_list		l;
	t_string	*s2;
	int			r;

	va_start(l, s);
	r = 0;
	while (!r && (s2 = va_arg(l, t_string *)))
		r = ft_string_insert(s, s->size, s2);
	va_end(l);
	return (r);
}
