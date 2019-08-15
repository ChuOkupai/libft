/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 03:07:21 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/15 05:51:28 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_iswspaces(int c)
{
	return (ft_isblank(c) || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	char	*d;
	size_t	n;

	while (ft_iswspaces(*s))
		s++;
	n = 0;
	while (s[n])
		n++;
	while (n && ft_iswspaces(s[n - 1]))
		n--;
	if ((d = (char*)malloc((n + 1) * sizeof(char))))
	{
		ft_memcpy(d, s, n);
		d[n] = '\0';
	}
	return (d);
}
