/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 04:29:29 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:41:10 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_macros.h"
#include "libft_stdio.h"
#define BUFFER_SIZE 4 * sizeof(int)

void	ft_putnbr_fd(int n, int fd)
{
	char			buf[BUFFER_SIZE];
	size_t			i;
	unsigned int	t;

	t = ABS(n);
	i = BUFFER_SIZE;
	while (t || i == BUFFER_SIZE)
	{
		buf[--i] = t % 10 + '0';
		t /= 10;
	}
	if (n < 0)
		buf[--i] = '-';
	(void)(write(fd, buf + i, BUFFER_SIZE - i) + 1);
}
