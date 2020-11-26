/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:11:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 16:32:09 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_realloc(void *src, size_t size, size_t new_size, bool fill)
{
	void *dst;

	if ((dst = ft_memdup(src, size, new_size, fill)))
		ft_free(src);
	return (dst);
}
