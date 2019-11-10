/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 05:22:00 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:48:44 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_memory.h"
#include "libft_string.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t n;

	if ((n = ft_strlen(src)) + 1 < dstsize)
		ft_memcpy(dst, src, n + 1);
	else if (dstsize)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (n);
}
