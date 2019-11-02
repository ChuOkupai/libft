/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 04:15:45 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/02 04:26:19 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putwchar_fd_4(int c, int fd)
{
	unsigned char t[4];

	t[0] = c >> 18 | 0xF0;
	t[1] = ((c >> 12) ^ (t[0] << 6)) | 0x80;
	t[2] = ((c >> 6) ^ (t[1] << 6)) | 0x80;
	t[3] = (c ^ (t[2] << 6)) | 0x80;
	(void)(write(fd, t, 4) + 1);
}

static void	ft_putwchar_fd_3(int c, int fd)
{
	unsigned char t[3];

	t[0] = c >> 12 | 0xe0;
	t[1] = ((c >> 6) ^ (t[0] << 6)) | 0x80;
	t[2] = (c ^ (t[1] << 6)) | 0x80;
	(void)(write(fd, t, 3) + 1);
}

static void	ft_putwchar_fd_2(int c, int fd)
{
	unsigned char t[2];

	t[0] = c >> 6 | 0xc0;
	t[1] = (c ^ (t[0] << 6)) | 0x80;
	(void)(write(fd, t, 2) + 1);
}

void		ft_putchar_fd(int c, int fd)
{
	if (c >> 16)
		ft_putwchar_fd_4(c, fd);
	else if (c >> 11)
		ft_putwchar_fd_3(c, fd);
	else if (c >> 7)
		ft_putwchar_fd_2(c, fd);
	else
		(void)(write(fd, &c, 1) + 1);
}
