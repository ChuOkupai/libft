/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 13:46:06 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/29 19:54:33 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_memory.h"
#include "ft_type.h"

void	*ft_memdup(const void *src, size_t alloc_size, size_t copy_size,
		bool fill)
{
	t_u8 *d;

	if (!(d = malloc(alloc_size)))
		return (NULL);
	if (alloc_size > copy_size && fill)
		ft_bzero(d + copy_size, alloc_size - copy_size);
	else if (copy_size > alloc_size)
		copy_size = alloc_size;
	return (ft_memcpy(d, src, copy_size));
}
