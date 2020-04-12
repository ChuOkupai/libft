/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 06:43:14 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/01 01:27:44 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	const char *s2;

	s2 = s;
	while (*s)
	{
		if (!*(++s))
			return (s - s2);
		if (!*(++s))
			return (s - s2);
		if (!*(++s))
			return (s - s2);
		if (!*(++s))
			return (s - s2);
		if (!*(++s))
			return (s - s2);
		if (!*(++s))
			return (s - s2);
		if (!*(++s))
			return (s - s2);
		if (!*(++s))
			return (s - s2);
		++s;
	}
	return (s - s2);
}
