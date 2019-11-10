/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 03:16:44 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:36:00 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void *d;

	if (dst < src)
	{
		d = dst;
		while (len--)
			*((unsigned char*)d++) = *((unsigned char*)src++);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
