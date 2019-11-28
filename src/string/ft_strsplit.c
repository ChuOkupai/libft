/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 03:29:19 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/28 23:36:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_memory.h"
#include "libft_string.h"

static size_t	ft_wordlen(const char **s, char c)
{
	while (**s && **s == c)
		(*s)++;
	return (ft_strchrnul(*s, c) - *s);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**t;
	const char	*s2;
	size_t		i;
	size_t		n;

	s2 = s;
	i = 0;
	while ((n = ft_wordlen(&s2, c)) && ++i)
		s2 += n;
	if (!(t = (char**)malloc((n + 1) * sizeof(char*))))
		return (NULL);
	i = 0;
	while ((n = ft_wordlen(&s, c)))
	{
		if (!(t[i++] = ft_strsub(s, 0, n)))
			return (ft_memdeltab((void***)&t, i - 1));
		s += n;
	}
	t[i] = 0;
	return (t);
}
