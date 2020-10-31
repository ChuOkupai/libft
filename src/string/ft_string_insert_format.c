/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_insert_format.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:13:55 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/31 16:41:19 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_memory.h"
#include "ft_stdio.h"
#include "ft_string.h"

int	ft_string_insert_format(t_string *s, size_t i, const char *format, ...)
{
	va_list	l;
	char	*s2;
	int		n;

	va_start(l, format);
	n = ft_vasprintf(&s2, format, l);
	va_end(l);
	if (n < 0)
		return (-1);
	n = ft_string_insert_str(s, i, s2);
	ft_delete(s2);
	return (n);
}
