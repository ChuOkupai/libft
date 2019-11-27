/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:50:44 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/27 16:26:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_list.h"
#include "libft_memory.h"
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

t_list			*ft_list_split(char const *s, char c)
{
	char	*str;
	t_list	*l;
	t_list	*e;
	size_t	n;

	l = NULL;
	while ((n = ft_wordlen(&s, c)))
	{
		str = ft_strsub(s, 0, n);
		if (!str || !(e = ft_list_new(str)))
		{
			ft_memdel((void**)(&str));
			ft_list_clear(&l, &free);
			break ;
		}
		ft_list_push(&l, e);
		s += n;
	}
	ft_list_rev(&l);
	return (l);
}
