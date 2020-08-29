/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 18:51:13 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/29 20:08:43 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_memory.h"
#include "ft_type.h"

static void	*search16(const t_u8 *b, size_t bl, const t_u8 *l)
{
	uint16_t lw;
	uint16_t bw;

	lw = *l << 8 | l[1];
	bw = *b << 8 | b[1];
	b += 2;
	bl -= 2;
	while (bl && bw != lw)
	{
		--bl;
		bw = bw << 8 | *b++;
	}
	return (bw == lw ? (void *)(b - 2) : NULL);
}

static void	*search24(const t_u8 *b, size_t bl, const t_u8 *l)
{
	uint32_t lw;
	uint32_t bw;

	lw = (uint32_t)*l << 24 | l[1] << 16 | l[2] << 8;
	bw = (uint32_t)*b << 24 | b[1] << 16 | b[2] << 8;
	b += 3;
	bl -= 3;
	while (bl && bw != lw)
	{
		--bl;
		bw = (bw | *b++) << 8;
	}
	return (bw == lw ? (void *)(b - 3) : NULL);
}

static void	*search32(const t_u8 *b, size_t bl, const t_u8 *l)
{
	uint32_t lw;
	uint32_t bw;

	lw = (uint32_t)*l << 24 | l[1] << 16 | l[2] << 8 | l[3];
	bw = (uint32_t)*b << 24 | b[1] << 16 | b[2] << 8 | b[3];
	b += 4;
	bl -= 4;
	while (bl && bw != lw)
	{
		--bl;
		bw = bw << 8 | *b++;
	}
	return (bw == lw ? (void *)(b - 4) : NULL);
}

static void	*naive_search(const t_u8 *b, size_t bl, const void *l, size_t ll)
{
	while (bl >= ll)
	{
		if (!ft_memcmp(b, l, ll))
			return ((void *)b);
		++b;
		--bl;
	}
	return (NULL);
}

void		*ft_memmem(const void *b, size_t bl, const void *l, size_t ll)
{
	const t_u8 *b8;
	const t_u8 *l8;

	if (!ll)
		return ((void *)b);
	else if (bl < ll)
		return (NULL);
	l8 = l;
	if (!(b8 = ft_memchr(b, *l8, bl)) || ll == 1)
		return ((void *)b8);
	if ((bl -= b8 - (const t_u8 *)b) < ll)
		return (NULL);
	if (ll == 2)
		return (search16(b8, bl, l8));
	if (ll == 3)
		return (search24(b8, bl, l8));
	if (ll == 4)
		return (search32(b8, bl, l8));
	return (naive_search(b8, bl, l, ll));
}
