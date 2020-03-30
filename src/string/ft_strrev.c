/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 06:43:52 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/30 01:47:08 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strrev(char *s)
{
	char	c;
	size_t	l;
	size_t	r;

	l = 0;
	if ((r = ft_strlen(s)))
		while (l < --r)
		{
			c = s[l];
			s[l++] = s[r];
			s[r] = c;
		}
	return (s);
}
