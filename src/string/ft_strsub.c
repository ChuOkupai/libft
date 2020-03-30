/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 00:54:04 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/25 14:03:15 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_memory.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char *d;

	if ((d = (char*)malloc((len + 1) * sizeof(char))))
	{
		ft_memcpy(d, s + start, len);
		d[len] = '\0';
	}
	return (d);
}
