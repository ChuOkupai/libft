/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 06:43:14 by asoursou          #+#    #+#             */
/*   Updated: 2019/10/20 19:09:44 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static const char	*ft_faststrlen(const char *s, const size_t *w,
					const size_t high_magic, const size_t low_magic)
{
	while (1)
		if ((((*w++) - low_magic) & high_magic))
		{
			if (!*(s = (const char *)(w - 1)))
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
		}
}

size_t				ft_strlen(const char *str)
{
	const char		*s;
	const size_t	*w;
	size_t			magic_bits;
	size_t			high_magic;
	size_t			low_magic;

	s = str;
	while ((size_t)s & (sizeof(size_t) - 1))
		++s;
	if (*s == '\0')
		return (s - str);
	magic_bits = 0x7efefeffL;
	low_magic = 0x01010101L;
	high_magic = 0x80808080L;
	if (sizeof(size_t) > 4)
	{
		magic_bits = ((0x7efefefeL << 16) << 16) | 0xfefefeffL;
		low_magic = ((low_magic << 16) << 16) | low_magic;
		high_magic = ((high_magic << 16) << 16) | high_magic;
	}
	return (ft_faststrlen(s, w = (size_t *)s, high_magic, low_magic) - str);
}
