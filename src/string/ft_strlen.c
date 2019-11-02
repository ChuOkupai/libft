/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 06:43:14 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/02 22:37:07 by asoursou         ###   ########.fr       */
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
	const char	*s;
	size_t		high_magic;
	size_t		low_magic;

	s = str;
	if (sizeof(size_t) > 8)
	{
		while (*s)
			s++;
		return (s - str);
	}
	while ((size_t)s & (sizeof(size_t) - 1))
		++s;
	if (*s == '\0')
		return (s - str);
	low_magic = 0x01010101L;
	high_magic = 0x80808080L;
	if (sizeof(size_t) > 4)
	{
		low_magic = ((low_magic << 16) << 16) | low_magic;
		high_magic = ((high_magic << 16) << 16) | high_magic;
	}
	return (ft_faststrlen(s, (size_t *)s, high_magic, low_magic) - str);
}
