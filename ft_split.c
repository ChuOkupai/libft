/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 03:29:19 by asoursou          #+#    #+#             */
/*   Updated: 2023/03/27 06:27:45 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**clear_array(char **t, size_t n)
{
	while (n--)
		free(t[n]);
	free(t);
	return (NULL);
}

static size_t	count_words(const char *s, const char c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s)
			++n;
		s = ft_strchrnul(s, c);
	}
	return (n);
}

char	**ft_split(const char *s, const char c)
{
	const size_t	n = count_words(s, c);
	char			**t;
	size_t			i;
	size_t			w;

	t = malloc(sizeof(*t) * (n + 1));
	if (!t)
		return (NULL);
	i = 0;
	while (i < n)
	{
		while (*s == c)
			++s;
		w = ft_strchrnul(s, c) - s;
		t[i] = ft_memdup_fill(s, w, w + 1);
		if (!t[i])
			return (clear_array(t, i));
		s += w;
		++i;
	}
	t[i] = NULL;
	return (t);
}
