/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 03:07:21 by asoursou          #+#    #+#             */
/*   Updated: 2019/10/08 12:12:56 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	t[128];
	size_t	n;

	ft_bzero(t, 128);
	while (set)
		t[*(int*)(set++)] = 1;
	while (t[(int)(*s1)])
		s1++;
	n = ft_strlen(s1);
	while (n && t[(int)(s1[n - 1])])
		n--;
	return (ft_substr(s1, 0, n));
}
