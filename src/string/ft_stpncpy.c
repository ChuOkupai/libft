/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 04:51:53 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/23 22:38:38 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_memory.h"

char	*ft_stpncpy(char *dst, const char *src, size_t len)
{
	while (len && *src)
	{
		*dst++ = *src++;
		--len;
	}
	ft_bzero(dst, len);
	return (dst);
}
