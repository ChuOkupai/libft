/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 00:14:04 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/30 03:29:29 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft_bit.h"
#include "libft_memory.h"

void	ft_bit_map(void *array, size_t size, const char *set)
{
	const uint8_t	*s;
	uint8_t			*map;

	s = (const uint8_t *)set;
	map = array;
	ft_bzero(map, size);
	while (*s)
	{
		map[*s / 8] |= 0x80 >> *s % 8;
		++s;
	}
}
