/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 06:43:14 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/09 13:35:05 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static const char	*ft_zerochr(const char *s)
{
	if (!s[0])
		return (s);
	if (!s[1])
		return (s + 1);
	if (!s[2])
		return (s + 2);
	if (!s[3])
		return (s + 3);
	if (sizeof(size_t) > 4)
	{
		if (!s[4])
			return (s + 4);
		if (!s[5])
			return (s + 5);
		if (!s[6])
			return (s + 6);
		if (!s[7])
			return (s + 7);
	}
	return (NULL);
}

static const char	*ft_faststrlen(const size_t *wp, const size_t hmgc,
					const size_t lmgc)
{
	const char *s;

	while (1)
		if (((*wp - lmgc) & ~(*wp) & hmgc) && (s = ft_zerochr((const char*)wp)))
			return (s);
		else
			++wp;
}

size_t				ft_strlen(const char *s)
{
	const char	*p;
	size_t		hmgc;
	size_t		lmgc;

	p = s;
	if (sizeof(size_t) > 8)
	{
		while (*p)
			++p;
		return (p - s);
	}
	while ((size_t)p & (sizeof(size_t) - 1) && *p)
		++p;
	if (!*p)
		return (p - s);
	hmgc = 0x80808080L;
	lmgc = 0x01010101L;
	if (sizeof(size_t) > 4)
	{
		hmgc = ((hmgc << 16) << 16) | hmgc;
		lmgc = ((lmgc << 16) << 16) | lmgc;
	}
	return (ft_faststrlen((size_t*)p, hmgc, lmgc) - s);
}
