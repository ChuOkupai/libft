/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:50:44 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/30 03:30:15 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "ft_const.h"
#include "libft_bit.h"
#include "libft_list.h"
#include "libft_memory.h"
#include "libft_string.h"

static size_t		ft_wordlen(const char **s, const void *map)
{
	const char *s2;

	while (ft_bit_at(map, **s))
		++(*s);
	s2 = *s;
	while (*s2 && !ft_bit_at(map, *s2))
		++s2;
	return (s2 - *s);
}

static const char	*ft_copy(t_list **l, const char *s, size_t n)
{
	char	*s2;
	t_list	*elem;

	s2 = ft_strsub(s, 0, n);
	if (s && (elem = ft_list_new(s2)))
	{
		ft_list_push(l, elem);
		return (s + n);
	}
	ft_memdel((void **)&s);
	ft_list_clear(l, &free);
	return (NULL);
}

t_list				*ft_list_split(const char *s, const char *set)
{
	uint8_t	map[32];
	t_list	*l;
	size_t	n;

	ft_bit_map(map, 32, (set ? set : FT_SPACE));
	l = NULL;
	while ((n = ft_wordlen(&s, map)))
		if (!(s = ft_copy(&l, s, n)))
			break ;
	return (ft_list_rev(l));
}
