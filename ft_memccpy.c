/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 01:35:55 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/14 02:56:25 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void *s;

	if ((s = ft_memchr(src, c, n)))
	{
		n = s - src + 1;
		s = dst + n;
	}
	ft_memcpy(dst, src, n);
	return (s);
}
