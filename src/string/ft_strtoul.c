/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 14:43:07 by asoursou          #+#    #+#             */
/*   Updated: 2019/12/24 15:27:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include "libft_ctype.h"

static const char	*ft_convert(const char *s, int *any, int base,
					unsigned long *n)
{
	char			c;
	unsigned long	cutoff;

	if (!base)
		base = *s == '0' ? 8 : 10;
	cutoff = (unsigned long)ULONG_MAX / (unsigned long)base;
	*any = 0;
	*n = 0;
	while ((c = ft_toupper(*s) - (ft_isdigit(*s) ? '0' : 55)) >= 0
		&& c < base)
	{
		if (*any < 0 || *n > cutoff || (*n == cutoff
			&& c > (int)((unsigned long)ULONG_MAX % (unsigned long)base)))
			*any = -1;
		else
		{
			*any = 1;
			*n = *n * base + c;
		}
		++s;
	}
	return (s);
}

unsigned long		ft_strtoul(const char *str, char **endptr, int base)
{
	const char		*s;
	int				sign;
	int				any;
	unsigned long	n;

	s = str;
	while (ft_isspace(*s))
		++s;
	if ((sign = *s == '-' ? -1 : 1) < 0 || *s == '+')
		++s;
	if ((base == 0 || base == 16) && *s == '0' && ft_tolower(s[1]) == 'x')
	{
		str = s + 1;
		s += 2;
		base = 16;
	}
	s = ft_convert(s, &any, base, &n);
	if (any < 0)
		n = ULONG_MAX;
	else if (sign < 0)
		n = -n;
	if (endptr)
		*endptr = (char *)(any ? s : str);
	return (n);
}
