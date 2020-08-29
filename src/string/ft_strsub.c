/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 00:54:04 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/29 20:00:07 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

char	*ft_strsub(const char *s, size_t start, size_t len)
{
	size_t n;

	if (start > len)
		start = len;
	s += start;
	if ((n = ft_strlen(s)) > len)
		n = len;
	return (ft_memdup(s, n + 1, n, true));
}
