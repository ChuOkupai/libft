/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 01:56:14 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 17:24:13 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_type.h"

static void	*chr(const t_u8 *s, t_u8 c, size_t n)
{
	if (!n)
		return (NULL);
	if (*s == c)
		return ((void*)s);
	return (chr(s + 1, c, n - 1));
}

void		*ft_memchr(const void *s, int c, size_t n)
{
	return (chr(s, c, n));
}
