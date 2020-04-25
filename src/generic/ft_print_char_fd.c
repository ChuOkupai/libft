/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 01:45:57 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 20:20:48 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_ctype.h"
#include "ft_stdio.h"

void	ft_print_char_fd(const void *character, int fd)
{
	char c;

	c = *((char*)character);
	if (c == '\'')
		ft_putstr_fd("'\\''", fd);
	else if (ft_isascii(c))
		ft_dprintf(fd, "'%c'", c);
	else
		ft_dprintf(fd, "'\\x%02hhx'", c);
}
