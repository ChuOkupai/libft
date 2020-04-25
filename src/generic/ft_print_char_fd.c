/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 01:45:57 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 12:25:06 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_stdio.h"

void	ft_print_char_fd(const void *content, int fd)
{
	char c;

	if ((c = *((char*)content)) == '\'')
		ft_putstr_fd("'\\''", fd);
	else
		ft_dprintf(fd, "'%c'", c);
}
