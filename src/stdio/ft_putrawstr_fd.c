/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putrawstr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:30:04 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 21:26:09 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_stdio.h"
#include "ft_string.h"

int			isprintable(int c)
{
	return (ft_isprint(c) && c != '"');
}

void		ft_putrawstr_fd(const char *s, int fd)
{
	int c;
	int n;

	ft_putchar_fd('"', fd);
	while (*s)
	{
		if ((n = ft_strwhile(s, &isprintable) - s))
			ft_putnstr_fd(s, n, fd);
		else if ((n = *s == '"'))
			ft_putstr_fd("\\\"", fd);
		else if ((n = ft_isascii(*s)))
		{
			c = ft_toprint(*s);
			ft_dprintf(fd, (c == *s ? "\\x%02hhx" : "\\%c"), c);
		}
		else
			ft_putnstr_fd(s, (n = ft_strwhilenot(s, &ft_isascii) - s), fd);
		s += n;
	}
	ft_putchar_fd('"', fd);
}
