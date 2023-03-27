/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 01:45:07 by asoursou          #+#    #+#             */
/*   Updated: 2023/03/27 06:05:53 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	const size_t	n1 = ft_strlen(s1);
	const size_t	n2 = ft_strlen(s2);
	char			*d;

	d = ft_memdup(s1, n1, n1 + n2 + 1);
	if (d)
	{
		ft_memcpy(d + n1, s2, n2);
		d[n1 + n2] = '\0';
	}
	return (d);
}
