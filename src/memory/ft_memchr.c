/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 01:56:14 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/02 16:51:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_type.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const t_u8 *t;

	t = s;
	while (n--)
	{
		if (*t == (unsigned char)c)
			return ((void *)t);
		++t;
	}
	return (NULL);
}
