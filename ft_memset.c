/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 02:50:39 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/13 02:47:55 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t m;

	m = (unsigned char)c;
	c = 1;
	while ((size_t)c < sizeof(m))
		m |= m << (8 * c++);
	while (len >= sizeof(len))
	{
		len -= sizeof(len);
		((size_t *)b)[len] = m;
	}
	while (len)
		((unsigned char *)b)[--len] = m;
	return (b);
}
