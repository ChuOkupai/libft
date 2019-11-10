/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 02:52:50 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:50:42 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t hlen;
	size_t nlen;

	if ((nlen = ft_strlen(needle)))
	{
		if (len < (hlen = ft_strlen(haystack)))
			hlen = len;
		while (hlen >= nlen && ft_strncmp(haystack, needle, nlen))
		{
			haystack++;
			hlen--;
		}
		if (hlen < nlen)
			return (NULL);
	}
	return ((char*)haystack);
}
