/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:23:54 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/19 20:57:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_stdio.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	l;
	int		n;

	va_start(l, format);
	n = ft_vdprintf(fd, format, l);
	va_end(l);
	return (n);
}
