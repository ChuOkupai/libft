/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 03:16:44 by asoursou          #+#    #+#             */
/*   Updated: 2023/11/02 16:23:00 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s = src;

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
