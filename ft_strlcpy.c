/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 05:22:00 by asoursou          #+#    #+#             */
/*   Updated: 2023/03/27 06:17:36 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;

	n = ft_strlen(src) + 1;
	if (n < size)
		ft_memcpy(dst, src, n);
	else if (size--)
	{
		ft_memcpy(dst, src, size);
		dst[size] = '\0';
	}
	return (n - 1);
}
