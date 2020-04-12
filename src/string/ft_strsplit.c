/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 03:29:19 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 02:04:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "ft_const.h"
#include "libft/ft_bit.h"
#include "libft/ft_memory.h"
#include "libft/ft_string.h"

static size_t	ft_wordlen(const char **s, const void *map)
{
	const char *s2;

	while (ft_bit_at(map, **s))
		++(*s);
	s2 = *s;
	while (*s2 && !ft_bit_at(map, *s2))
		++s2;
	return (s2 - *s);
}

static size_t	ft_wordcount(const char *s, const void *map)
{
	size_t i;
	size_t n;

	i = 0;
	while ((n = ft_wordlen(&s, map)))
	{
		++i;
		s += n;
	}
	return (i);
}

char			**ft_strsplit(const char *s, const char *set)
{
	uint8_t	map[32];
	char	**t;
	size_t	i;
	size_t	n;

	ft_bit_map(map, 32, (set ? set : FT_SPACE));
	if (!(t = (char**)malloc((ft_wordcount(s, map) + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	while ((n = ft_wordlen(&s, map)))
		if ((t[i++] = ft_strsub(s, 0, n)))
			s += n;
		else
			return (ft_memdeltab((void***)&t, i - 1));
	t[i] = NULL;
	return (t);
}
