/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 03:07:21 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/30 03:32:19 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_const.h"
#include "libft_bit.h"
#include "libft_memory.h"
#include "libft_string.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	uint8_t	map[32];
	size_t	n;

	ft_bit_map(map, 32, (set ? set : FT_SPACE));
	while (ft_bit_at(map, *s1))
		s1++;
	n = ft_strlen(s1);
	while (n && ft_bit_at(map, s1[n - 1]))
		n--;
	return (ft_strsub(s1, 0, n));
}
