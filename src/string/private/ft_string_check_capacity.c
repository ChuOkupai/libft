/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_check_capacity.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:21:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/31 17:15:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>
#include "ft_memory.h"
#include "ft_string_utils.h"

static size_t	uadd_no_overflow(size_t a, size_t b)
{
	return (a > ULONG_MAX - b ? ULONG_MAX : a + b);
}

static size_t	next_capacity(size_t n)
{
	if (!n)
		return (FT_STRING_BUF_INIT_SIZE);
	if (n == ULONG_MAX)
		return (!(errno = ERANGE));
	if (n < 256)
		return (uadd_no_overflow(n, n));
	return (uadd_no_overflow(n, n / 2));
}

bool			ft_string_check_capacity(t_string *s, size_t size)
{
	char	*buf;
	size_t	n;

	if (s->capacity - s->size > size)
		return (true);
	n = s->capacity;
	while ((n = next_capacity(n)) && n < s->size + size + 1)
		continue ;
	if (!n || !(buf = ft_realloc(s->buf, s->size, n, false)))
		return (false);
	s->buf = buf;
	s->capacity = n;
	return (true);
}
