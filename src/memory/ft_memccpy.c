/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 01:35:55 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 17:24:34 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_type.h"

static void	*ccpy(t_u8 *d, const t_u8 *s, t_u8 c, size_t n)
{
	if (!n)
		return (NULL);
	*d++ = *s;
	if (*s == c)
		return (d);
	return (ccpy(d, s + 1, c, n - 1));
}

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	return (ccpy(dst, src, c, n));
}
