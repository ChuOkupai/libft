/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 01:35:55 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/27 01:33:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_type.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	t_u8		*d;
	const t_u8	*s;

	d = dst;
	s = src;
	while (n--)
	{
		*d++ = *s;
		if (*s++ == (t_u8)c)
			return (d);
	}
	return (NULL);
}
