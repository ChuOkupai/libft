/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 02:31:01 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 19:45:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void	ft_bzero(void *s, size_t n)
{
	while (n >= 8 * sizeof(size_t))
	{
		((size_t *)s)[0] = 0;
		((size_t *)s)[1] = 0;
		((size_t *)s)[2] = 0;
		((size_t *)s)[3] = 0;
		((size_t *)s)[4] = 0;
		((size_t *)s)[5] = 0;
		((size_t *)s)[6] = 0;
		((size_t *)s)[7] = 0;
		s += 8 * sizeof(size_t);
		n -= 8 * sizeof(size_t);
	}
	while (n >= sizeof(size_t))
	{
		*((size_t *)s) = 0;
		s += sizeof(size_t);
		n -= sizeof(size_t);
	}
	while (n)
		((unsigned char *)s)[--n] = 0;
}
