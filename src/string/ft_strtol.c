/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 00:04:04 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/27 11:16:07 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>
#include "ft_ctype.h"
#include "ft_type.h"

static t_u64	next_value(t_u64 c, t_u64 base)
{
	if (ft_isdigit(c))
		c -= '0';
	else
		c = ft_isalpha(c) ? (t_u64)ft_tolower(c) - 'a' + 10 : base;
	return (c);
}

static t_s64	check_limit(t_u64 c, t_u64 n, t_u64 cutoff, t_u64 cutlim)
{
	return (n > cutoff || (n == cutoff && c > cutlim) ? -1 : 1);
}

static long		check_result(t_u64 n, t_s64 lim, bool neg)
{
	if (!lim)
		errno = EINVAL;
	else if (lim < 0)
	{
		errno = ERANGE;
		return (neg ? LONG_MIN : LONG_MAX);
	}
	else if (!neg && n > (t_u64)LONG_MAX)
	{
		errno = ERANGE;
		n = LONG_MAX;
	}
	return (neg ? -n : n);
}

static long		parse(const char *s, const char **end, t_u64 base, bool neg)
{
	t_u64	cutoff;
	t_u64	cutlim;
	t_u64	c;
	t_u64	n;
	t_s64	lim;

	cutoff = (t_u64)LONG_MIN / base;
	cutlim = (t_u64)LONG_MIN % base;
	lim = 0;
	n = 0;
	while ((c = next_value(*s++, base)) < base)
		if (lim >= 0 && (lim = check_limit(c, n, cutoff, cutlim)))
			n = n * base + c;
	*end = lim ? s - 1 : NULL;
	return (check_result(n, lim, neg));
}

long			ft_strtol(const char *str, char **endptr, int base)
{
	const char	*s;
	bool		neg;
	long		n;

	s = str;
	while (ft_isspace(*s))
		++s;
	if ((neg = *s == '-') || *s == '+')
		++s;
	if ((!base || base == 16) && *s == '0' && (s[1] == 'x' || s[1] == 'X'))
	{
		str = s + 1;
		s += 2;
		base = 16;
	}
	else if (!base)
		base = *s == '0' ? 8 : 10;
	n = parse(s, &s, base, neg);
	if (endptr)
		*endptr = (char *)(s ? s : str);
	return (n);
}
