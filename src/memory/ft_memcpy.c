/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 01:56:55 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 17:21:30 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_type.h"

static void	*descending_copy(t_u8 *d, const t_u8 *s, size_t n)
{
	while (n--)
		d[n] = s[n];
	return (d);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	return (descending_copy(dst, src, n));
}
