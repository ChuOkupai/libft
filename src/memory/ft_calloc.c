/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:05:59 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:34:39 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_memory.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *b;

	size *= count;
	if ((b = (void*)malloc(size)))
		ft_bzero(b, size);
	return (b);
}
