/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 02:50:39 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/13 08:08:20 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*static void	ft_fastmemset(void *b, size_t m, size_t n)
{
		((size_t *)b)[0] = m;
		((size_t *)b)[1] = m;
		((size_t *)b)[2] = m;
		((size_t *)b)[3] = m;
		((size_t *)b)[4] = m;
		((size_t *)b)[5] = m;
		((size_t *)b)[6] = m;
		((size_t *)b)[7] = m;
}*/

void		*ft_memset(void *b, int c, size_t len)
{
	size_t i;
	size_t mask;

	mask = (unsigned char)c;
	c = 1;
	while ((size_t)c < sizeof(mask))
	{
		mask |= mask << (c << 3);
		c <<= 1;
	}
	i = len / sizeof(i);
	while (i)
		((size_t *)b)[--i] = mask;
	i = len - len % sizeof(i);
	while (i < len)
		((unsigned char *)b)[i++] = mask;
	return (b);
}
