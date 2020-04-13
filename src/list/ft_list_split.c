/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:50:44 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/13 01:29:44 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "ft_const.h"
#include "ft_bit.h"
#include "ft_list.h"
#include "ft_memory.h"

static size_t	ft_wordlen(const char **s, const uint8_t *map)
{
	const char *set;

	while (ft_bit_at(map, (uint8_t)**s))
		++(*s);
	set = *s;
	while (*set && !ft_bit_at(map, (uint8_t)*set))
		++set;
	return (set - *s);
}

t_list			*ft_list_split(const char *s, const char *set)
{
	uint8_t	map[32];
	t_list	*l;
	char	*s2;
	size_t	n;

	ft_bit_map(map, 32, (set ? set : FT_SPACE));
	l = NULL;
	while ((n = ft_wordlen(&s, map)))
	{
		s2 = ft_memdup(s, n + 1, n);
		if (!s2 || !ft_list_push(&l, ft_list_new(s2)))
		{
			ft_memdel((void **)&s2);
			return (ft_list_clear(&l, &free));
		}
		s += n;
	}
	return (ft_list_rev(l));
}
