/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:14:38 by asoursou          #+#    #+#             */
/*   Updated: 2020/02/09 01:47:50 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_stdio.h"

int	ft_snprintf(char *str, size_t n, const char *format, ...)
{
	va_list	l;
	int		size;

	va_start(l, format);
	size = ft_vsnprintf(str, n, format, l);
	va_end(l);
	return (size);
}
