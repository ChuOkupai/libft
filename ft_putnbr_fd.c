/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 04:29:29 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/05 13:39:24 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define BUFFER_SIZE 4 * sizeof(int)

void	ft_putnbr_fd(int n, int fd)
{
	char			buf[BUFFER_SIZE];
	size_t			i;
	unsigned int	t;

	t = (n < 0) ? -n : n;
	n = (n < 0);
	i = BUFFER_SIZE;
	while (t || i == BUFFER_SIZE)
	{
		buf[--i] = t % 10 + '0';
		t /= 10;
	}
	if (n)
		buf[--i] = '-';
	(void)(write(fd, buf + i, BUFFER_SIZE - i) + 1);
}
