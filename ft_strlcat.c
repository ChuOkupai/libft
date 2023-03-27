/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 05:21:23 by asoursou          #+#    #+#             */
/*   Updated: 2023/03/27 06:18:26 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const size_t	i = ft_strnlen(dst, size);
	size_t			j;

	if (i == size)
		return (ft_strlen(src) + i);
	dst += i;
	j = 0;
	while (src[j])
	{
		if (i + j + 1 < size)
			*dst++ = src[j];
		++j;
	}
	*dst = '\0';
	return (i + j);
}
