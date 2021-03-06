/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:23:54 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 13:07:34 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_stdio.h"

int	ft_printf(const char *format, ...)
{
	va_list	l;
	int		size;

	va_start(l, format);
	size = ft_vdprintf(STDOUT_FILENO, format, l);
	va_end(l);
	return (size);
}
