/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 06:43:14 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 17:14:47 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	len(const char *s)
{
	if (!*s)
		return (0);
	return (1 + len(s + 1));
}

size_t			ft_strlen(const char *s)
{
	if (!s)
		return (0);
	return (len(s));
}
