/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:23:54 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/19 21:18:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_stdio.h"

int	ft_printf(const char *format, ...)
{
	va_list	l;
	int		n;

	va_start(l, format);
	n = ft_vdprintf(STDOUT_FILENO, format, l);
	va_end(l);
	return (n);
}
