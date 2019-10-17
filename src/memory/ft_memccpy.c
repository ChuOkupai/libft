/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 01:35:55 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/14 20:10:05 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n)
	{
		*((unsigned char*)dst) = *((unsigned char*)src);
		if (*((unsigned char*)dst) == (unsigned char)c)
			return (dst + 1);
		src++;
		dst++;
		n--;
	}
	return (NULL);
}
