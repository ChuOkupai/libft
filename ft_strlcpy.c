/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 05:22:00 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/13 19:47:05 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	if ((i = ft_strlen(src)) + 1 < dstsize)
		ft_memcpy(dst, src, i + 1);
	else if (dstsize)
	{
		while (--dstsize)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (i);
}
