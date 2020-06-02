/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 03:27:06 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/02 16:52:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_type.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const t_u8 *a;
	const t_u8 *b;

	a = s1;
	b = s2;
	while (n--)
	{
		if (*a != *b)
			return (*a - *b);
		++a;
		++b;
	}
	return (0);
}
