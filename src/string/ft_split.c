/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 03:29:19 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:45:16 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_string.h"

static size_t	ft_wordlen(const char **s, char c)
{
	size_t n;

	while (**s && **s == c)
		(*s)++;
	n = 0;
	while ((*s)[n] && (*s)[n] != c)
		n++;
	return (n);
}

static size_t	ft_wordcount(const char *s, char c)
{
	size_t n;
	size_t w;

	w = 0;
	while (*s)
	{
		if ((n = ft_wordlen(&s, c)))
			w++;
		s += n;
	}
	return (w);
}

char			**ft_split(char const *s, char c)
{
	char	**t;
	size_t	i;
	size_t	n;
	size_t	size;

	size = ft_wordcount(s, c);
	if (!(t = (char**)malloc((size + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		n = ft_wordlen(&s, c);
		if (!(t[i] = ft_substr(s, 0, n)))
		{
			while (i)
				free(t[--i]);
			free(t);
			return (NULL);
		}
		s += n;
		i++;
	}
	t[i] = 0;
	return (t);
}
