/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 05:22:00 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/12 06:23:24 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	if ((i = ft_strlen(src)) + 1 < dstsize)
		ft_strcpy(dst, src);
	else if (dstsize)
	{
		while (--dstsize)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (i);
}
