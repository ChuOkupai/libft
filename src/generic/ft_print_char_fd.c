/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 01:45:57 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/08 02:35:57 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_stdio.h"
#include "ft_type.h"

void	ft_print_char_fd(const void *character, int fd)
{
	t_u32	c;
	t_u8	p;

	c = (t_u8)(*((char*)character));
	if (ft_isprint(c))
	{
		if (c == '\'')
			ft_putstr_fd("'\\''", fd);
		else
			ft_dprintf(fd, "'%c'", c);
	}
	else
	{
		p = ft_toprint(c);
		ft_dprintf(fd, (c == p ? "'\\x%hhx'" : "'\\%c'"), p);
	}
}
