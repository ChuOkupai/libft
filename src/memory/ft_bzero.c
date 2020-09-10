/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 02:31:01 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/10 12:42:08 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_type.h"

static void	bigset(size_t *s, size_t n)
{
	while (n >= 8 * sizeof(size_t))
	{
		s[0] = 0;
		s[1] = 0;
		s[2] = 0;
		s[3] = 0;
		s[4] = 0;
		s[5] = 0;
		s[6] = 0;
		s[7] = 0;
		s += 8;
		n -= 8 * sizeof(size_t);
	}
	while (n >= sizeof(size_t))
	{
		*s++ = 0;
		n -= sizeof(size_t);
	}
	while (n)
		((t_u8 *)s)[--n] = 0;
}

void		ft_bzero(void *s, size_t n)
{
	if (n == 1)
		*((t_u8 *)s) = 0;
	else
		bigset(s, n);
}
