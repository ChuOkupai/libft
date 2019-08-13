/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 01:56:55 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/13 17:49:29 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static void	ft_fastcpy(void *d, const void *s, size_t n)
{
	while (n >= 8 * sizeof(size_t))
	{
		((size_t *)d)[0] = ((size_t *)s)[0];
		((size_t *)d)[1] = ((size_t *)s)[1];
		((size_t *)d)[2] = ((size_t *)s)[2];
		((size_t *)d)[3] = ((size_t *)s)[3];
		((size_t *)d)[4] = ((size_t *)s)[4];
		((size_t *)d)[5] = ((size_t *)s)[5];
		((size_t *)d)[6] = ((size_t *)s)[6];
		((size_t *)d)[7] = ((size_t *)s)[7];
		d += 8 * sizeof(size_t);
		s += 8 * sizeof(size_t);
		n -= 8 * sizeof(size_t);
	}
	while (n >= sizeof(size_t))
	{
		*((size_t *)d) = *((size_t *)s);
		d += sizeof(size_t);
		s += sizeof(size_t);
		n -= sizeof(size_t);
	}
	while (n--)
		((unsigned char *)d)[n] = ((unsigned char *)s)[n];
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	ft_fastcpy(dst, src, n);
	return (dst);
}
