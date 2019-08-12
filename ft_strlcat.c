/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 05:21:23 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/12 06:37:30 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < dstsize && dst[i])
		i++;
	if (i == dstsize)
		return (i + ft_strlen(src));
	dst += i;
	j = 0;
	while (src[j])
	{
		if (j < dstsize - i - 1)
			*dst++ = src[j];
		j++;
	}
	*dst = '\0';
	return (i + j);
}
