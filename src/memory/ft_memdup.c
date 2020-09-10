/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 13:46:06 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/10 12:31:16 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_memory.h"
#include "ft_type.h"

void	*ft_memdup(const void *src, size_t size, size_t new_size, bool fill)
{
	t_u8 *d;

	if (!(d = malloc(new_size)))
		return (NULL);
	if (new_size > size && fill)
		ft_bzero(d + size, new_size - size);
	else if (size > new_size)
		size = new_size;
	return (ft_memcpy(d, src, size));
}
