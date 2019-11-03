/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 04:15:45 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/03 03:25:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_charlen(char *b, int c)
{
	if (c < 0x80)
	{
		b[0] = c;
		return (1);
	}
	else if (c < 0x800)
	{
		b[0] = 0xc0 | c >> 6;
		b[1] = 0x80 | (c >> 0 & 0x3f);
		return (2);
	}
	else if (c < 0x10000)
	{
		b[0] = 0xe0 | c >> 12;
		b[1] = 0x80 | (c >> 6 & 0x3f);
		b[2] = 0x80 | (c >> 0 & 0x3f);
		return (3);
	}
	b[0] = 0xf0 | c >> 18;
	b[1] = 0x80 | (c >> 12 & 0x3f);
	b[2] = 0x80 | (c >> 6 & 0x3f);
	b[3] = 0x80 | (c >> 0 & 0x3f);
	return (4);
}

void		ft_putchar_fd(int c, int fd)
{
	char b[4];
	
	(void)(write(fd, b, ft_charlen(b, c)) + 1);
}
