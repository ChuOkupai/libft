/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 05:56:00 by asoursou          #+#    #+#             */
/*   Updated: 2023/03/27 06:15:46 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup_fill(const void *src, size_t size, size_t new_size)
{
	t_u8	*d;

	d = ft_memdup(src, size, new_size);
	if (d && new_size > size)
		ft_bzero(d + size, new_size - size);
	return (d);
}
