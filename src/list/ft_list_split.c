/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:50:44 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 12:37:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_bit.h"
#include "ft_const.h"
#include "ft_list.h"
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

t_list			*ft_list_split(const char *s, const char *set)
{
	t_u8	map[32];
	t_list	*l;
	char	*s2;
	size_t	n;

	ft_bit_map(map, 32, (set ? set : FT_SPACE));
	l = NULL;
	while ((n = ft_wordlen(&s, map)))
	{
		s2 = ft_memdup(s, n, n + 1, true);
		if (!s2 || !ft_list_push(&l, ft_list_new(s2)))
		{
			s2 = ft_free(s2);
			return (ft_list_clear(&l, &free));
		}
		s += n;
	}
	return (ft_list_rev(l));
}
