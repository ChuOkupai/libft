/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 02:52:50 by asoursou          #+#    #+#             */
/*   Updated: 2019/10/07 14:48:19 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_kmp_init(int *t, const char *n, size_t nl)
{
	size_t i;
	size_t j;

	ft_memset(t, 0, (nl + 1) * sizeof(int));
	i = 0;
	while (++i < nl)
	{
		j = t[i + 1];
		while (j > 0 && n[j] != n[i])
			j = t[j];
		if (j > 0 || n[j] == n[i])
			t[i + 1] = j + 1;
	}
}

static char	*ft_kmp_search(const char *h, const char *n, size_t hl, size_t nl)
{
	int		t[nl + 1];
	size_t	i;
	size_t	j;

	ft_kmp_init(t, n, nl);
	i = 0;
	j = 0;
	while (hl - i >= nl)
	{
		if (h[i] == n[j])
		{
			i++;
			if (++j == nl)
				return ((char*)h + i - j);
		}
		else
			(j) ? j = t[j] : i++;
	}
	return (NULL);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t hl;
	size_t nl;

	if (!(nl = ft_strlen(needle)))
		return ((char*)haystack);
	if (len < (hl = ft_strlen(haystack)))
		hl = len;
	if (hl < nl)
		return (NULL);
	return (ft_kmp_search(haystack, needle, hl, nl));
}
