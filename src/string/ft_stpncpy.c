/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 04:51:53 by asoursou          #+#    #+#             */
/*   Updated: 2020/02/10 00:30:11 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_memory.h"

char	*ft_stpncpy(char *dst, const char *src, size_t len)
{
	while (len && *src)
	{
		*dst++ = *src++;
		--len;
	}
	return (ft_memset(dst, '\0', len));
}
