/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 02:21:09 by asoursou          #+#    #+#             */
/*   Updated: 2019/12/03 12:16:26 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_memory.h"
#include "libft_string.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*d;
	size_t	m;

	m = ft_strlen(s1);
	n = n < m ? n : m;
	if ((d = (char*)malloc((n + 1) * sizeof(char))))
	{
		ft_memcpy(d, s1, n);
		d[n] = '\0';
	}
	return (d);
}
