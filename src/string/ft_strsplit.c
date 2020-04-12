/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 03:29:19 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 19:41:49 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include "ft_memory.h"

char	**ft_strsplit(const char *s, const char *set)
{
	char	**t;
	t_list	*l;
	size_t	i;

	l = ft_list_split(s, set);
	if (!l || !(t = (char**)malloc((ft_list_size(l) + 1) * sizeof(char*))))
		return (ft_list_clear(&l, &free));
	i = 0;
	while (l)
		t[i] = ft_list_pop(&l, NULL);
	t[i] = NULL;
	return (t);
}
