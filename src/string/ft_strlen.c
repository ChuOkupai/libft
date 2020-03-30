/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 06:43:14 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/30 01:48:25 by asoursou         ###   ########.fr       */
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
			break ;
		if (!*(++s))
			break ;
		if (!*(++s))
			break ;
		if (!*(++s))
			break ;
		if (!*(++s))
			break ;
		if (!*(++s))
			break ;
		if (!*(++s))
			break ;
		if (!*(++s))
			break ;
	}
	return (s - s2);
}
