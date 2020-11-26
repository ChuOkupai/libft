/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 20:11:54 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 12:28:24 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

char	*ft_strjoin3(const char *s1, const char *s2, const char *s3)
{
	char	*d;
	size_t	n1;
	size_t	n2;
	size_t	n3;

	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	n3 = ft_strlen(s3);
	if ((d = ft_malloc(n1 + n2 + n3 + 1)))
	{
		ft_memcpy(d, s1, n1);
		ft_memcpy(d + n1, s2, n2);
		ft_memcpy(d + n1 + n2, s3, n3);
		d[n1 + n2 + n3] = '\0';
	}
	return (d);
}
