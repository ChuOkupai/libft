/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 04:56:45 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/12 05:16:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			i = 1;
			while (needle[i] && haystack[i] == needle[i])
				i++;
			if (!needle[i])
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
