/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:33:15 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/24 18:43:33 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bit.h"
#include "ft_const.h"
#include "ft_dlist.h"
#include "ft_memory.h"
#include "ft_type.h"

static size_t	ft_wordlen(const char **s, const t_u8 *map)
{
	const char *set;

	while (ft_bit_at(map, (t_u8)**s))
		++(*s);
	set = *s;
	while (*set && !ft_bit_at(map, (t_u8)*set))
		++set;
	return (set - *s);
}

t_dlist			*ft_dlist_split(const char *s, const char *set)
{
	t_u8	map[32];
	t_dlist	*l;
	char	*s2;
	size_t	n;

	ft_bit_map(map, 32, (set ? set : FT_SPACE));
	l = NULL;
	while ((n = ft_wordlen(&s, map)))
	{
		s2 = ft_memdup(s, n + 1, n);
		if (!s2 || !ft_dlist_push(&l, ft_dlist_new(s2)))
		{
			s2 = ft_memdel(s2);
			return (ft_dlist_clear(&l, &free));
		}
		s += n;
	}
	return (ft_dlist_rev(l));
}
