/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 03:27:06 by asoursou          #+#    #+#             */
/*   Updated: 2023/03/27 04:16:45 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const t_u8	*a = s1;
	const t_u8	*b = s2;

	while (n)
	{
		if (*a != *b)
			return (*a - *b);
		++a;
		++b;
		--n;
	}
	return (0);
}
