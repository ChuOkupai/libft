/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 03:16:44 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/02 16:55:09 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_type.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	t_u8		*d;
	const t_u8	*s;

	s = src;
	if (dst < src)
	{
		d = dst;
		while (len--)
			*d++ = *s++;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
