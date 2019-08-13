/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 04:56:45 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/13 02:12:16 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t hlen;
	size_t nlen;

	if ((nlen = ft_strlen(needle)))
	{
		hlen = ft_strlen(haystack);
		while (hlen >= nlen && ft_strncmp(haystack, needle, nlen))
		{
			haystack++;
			hlen--;
		}
		if (hlen < nlen)
			haystack += hlen;
	}
	return ((char *)haystack);
}
