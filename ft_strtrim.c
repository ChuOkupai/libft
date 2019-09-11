/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 03:07:21 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/11 17:02:06 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswspaces(int c)
{
	return (ft_isblank(c) || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	size_t n;

	while (ft_iswspaces(*s))
		s++;
	n = ft_strlen(s);
	while (n && ft_iswspaces(s[n - 1]))
		n--;
	return (ft_strsub(s, 0, n));
}
