/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 01:45:07 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/31 15:42:43 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*d;
	size_t	n1;
	size_t	n2;

	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	if ((d = ft_new(n1 + n2 + 1)))
	{
		ft_memcpy(d, s1, n1);
		ft_memcpy(d + n1, s2, n2);
		d[n1 + n2] = '\0';
	}
	return (d);
}
