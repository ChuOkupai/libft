/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 13:46:06 by asoursou          #+#    #+#             */
/*   Updated: 2023/11/02 16:31:09 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t size, size_t new_size)
{
	unsigned char	*d;

	d = malloc(new_size);
	if (d)
		return (ft_memcpy(d, src, ft_bound_size_t(size, new_size)));
	return (d);
}
