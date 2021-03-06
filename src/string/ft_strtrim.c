/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 03:07:21 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/10 12:33:10 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bit.h"
#include "ft_const.h"
#include "ft_memory.h"
#include "ft_string.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	t_u8	map[32];
	size_t	n;

	ft_bit_map(map, 32, (set ? set : FT_SPACE));
	while (ft_bit_at(map, *s1))
		++s1;
	n = ft_strlen(s1);
	while (n && ft_bit_at(map, s1[n - 1]))
		--n;
	return (ft_memdup(s1, n, n + 1, true));
}
