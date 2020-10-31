/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 03:07:21 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/31 15:24:56 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bit.h"
#include "ft_const.h"
#include "ft_memory.h"
#include "ft_string.h"

char	*ft_strtrim(const char *s1, const char *charset)
{
	t_u8	map[32];
	size_t	n;

	if ((n = ft_strlen(s1)))
	{
		ft_bit_map(map, 32, (charset ? charset : FT_SPACE));
		while (ft_bit_at(map, *s1))
			++s1;
		while (n && ft_bit_at(map, s1[n - 1]))
			--n;
	}
	return (ft_memdup(s1, n, n + 1, true));
}
