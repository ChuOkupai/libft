/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 03:27:06 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 15:13:34 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_type.h"

static int	cmp(const t_u8 *a, const t_u8 *b, size_t n)
{
	if (!n)
		return (0);
	if (*a != *b)
		return (*a - *b);
	return (cmp(a + 1, b + 1, n - 1));
}

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	return (cmp(s1, s2, n));
}
