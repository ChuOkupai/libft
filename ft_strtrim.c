/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 03:07:21 by asoursou          #+#    #+#             */
/*   Updated: 2019/10/10 21:24:38 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	t[256];
	size_t	n;

	ft_bzero(t, 256);
	while (set)
		t[(unsigned int)(*(set++))] = 1;
	while (t[(unsigned int)(*s1)])
		s1++;
	n = ft_strlen(s1);
	while (n && t[(unsigned int)(s1[n - 1])])
		n--;
	return (ft_substr(s1, 0, n));
}
