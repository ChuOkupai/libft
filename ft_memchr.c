/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 01:56:14 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/15 04:04:45 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n)
	{
		if (*((unsigned char*)s) == (unsigned char)c)
			return ((void*)s);
		s += sizeof(unsigned char);
		n--;
	}
	return (NULL);
}
