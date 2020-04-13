/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:30:04 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/13 01:34:47 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_string.h"

void	ft_print_str_fd(const void *content, int fd)
{
	char	*s;
	int		n;

	ft_putchar_fd('"', fd);
	s = (char*)content;
	while (s[(n = ft_strchrnul(s, '"') - s)])
	{
		if (n)
			ft_dprintf(fd, "%.*s\\\"", n, s);
		else
			ft_dprintf(fd, "\\\"");
		s += n + 1;
	}
	if (n)
		ft_putstr_fd(s, fd);
	ft_putchar_fd('"', fd);
}
