/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 04:29:29 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/15 05:45:30 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char			buf[11];
	size_t			i;
	unsigned int	t;

	t = (n < 0) ? -n : n;
	n = (n < 0);
	i = 11;
	while (1)
	{
		buf[--i] = t % 10 + '0';
		if (!(t /= 10))
			break;
	}
	if (n)
		buf[--i] = '-';
	write(fd, buf + i, 11 - i);
}
