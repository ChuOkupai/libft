/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 02:50:39 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/15 04:06:28 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

static void	ft_fastset(void *b, size_t m, size_t n)
{
	while (n >= 8 * sizeof(size_t))
	{
		((size_t*)b)[0] = m;
		((size_t*)b)[1] = m;
		((size_t*)b)[2] = m;
		((size_t*)b)[3] = m;
		((size_t*)b)[4] = m;
		((size_t*)b)[5] = m;
		((size_t*)b)[6] = m;
		((size_t*)b)[7] = m;
		b += 8 * sizeof(size_t);
		n -= 8 * sizeof(size_t);
	}
	while (n >= sizeof(size_t))
	{
		*((size_t*)b) = m;
		b += sizeof(size_t);
		n -= sizeof(size_t);
	}
	while (n)
		((unsigned char*)b)[--n] = m;
}

void		*ft_memset(void *b, int c, size_t len)
{
	size_t mask;

	mask = (unsigned char)c;
	c = 1;
	while ((size_t)c < sizeof(size_t))
	{
		mask |= mask << (c << 3);
		c <<= 1;
	}
	ft_fastset(b, mask, len);
	return (b);
}
