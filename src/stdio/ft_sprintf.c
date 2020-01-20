/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 20:35:40 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/20 20:52:37 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft_stdio.h"

int	ft_sprintf(char *str, const char *format, ...)
{
	va_list	l;
	int		n;

	va_start(l, format);
	n = ft_vsprintf(str, format, l);
	va_end(l);
	return (n);
}
