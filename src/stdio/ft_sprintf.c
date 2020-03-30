/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:35:40 by asoursou          #+#    #+#             */
/*   Updated: 2020/02/09 01:47:54 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_stdio.h"

int	ft_sprintf(char *str, const char *format, ...)
{
	va_list	l;
	int		size;

	va_start(l, format);
	size = ft_vsprintf(str, format, l);
	va_end(l);
	return (size);
}
