/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 01:46:57 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 18:24:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

int	ft_asprintf(char **ret, const char *format, ...)
{
	va_list	l;
	int		size;

	va_start(l, format);
	size = ft_vasprintf(ret, format, l);
	va_end(l);
	return (size);
}
