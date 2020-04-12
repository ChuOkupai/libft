/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 13:46:06 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 18:24:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_memory.h"

void	*ft_memdup(const void *src, size_t alloc_size, size_t copy_size)
{
	void *d;

	if (!(d = malloc(alloc_size)))
		return (NULL);
	if (alloc_size > copy_size)
		ft_bzero(d + copy_size, alloc_size - copy_size);
	else if (copy_size > alloc_size)
		copy_size = alloc_size;
	return (ft_memcpy(d, src, copy_size));
}
