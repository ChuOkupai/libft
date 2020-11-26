/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 03:16:44 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 14:58:47 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_type.h"

static void	ascending_copy(t_u8 *d, const t_u8 *s, size_t n)
{
	if (!n)
		return ;
	*d = *s;
	ascending_copy(d + 1, s + 1, n - 1);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
		return (ft_memcpy(dst, src, len));
	ascending_copy(dst, src, len);
	return (dst);
}
