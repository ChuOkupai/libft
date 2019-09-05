/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 02:36:38 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/05 01:51:28 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#define BUFFER_SIZE 8 * sizeof(int)

static void	ft_print(int n, char const *base, int size, int fd)
{
	char			buf[BUFFER_SIZE];
	size_t			i;
	unsigned int	t;

	t = (n < 0) ? -n : n;
	n = (n < 0);
	i = BUFFER_SIZE;
	while (t || i == BUFFER_SIZE)
	{
		buf[--i] = base[t % size];
		t /= size;
	}
	if (n)
		buf[--i] = '-';
	write(fd, buf + i, BUFFER_SIZE - i);
}

void		ft_putnbr_base_fd(int n, char const *base, int fd)
{
	char	t[128];
	int		i;

	i = -1;
	ft_memset(t, 0, 128);
	while (base[++i] && ft_isgraph(base[i]) && base[i] != '+' && base[i] != '-'
		&& !t[(int)base[i]])
		t[(int)base[i]] = 1;
	if (i > 1 && !base[i])
		ft_print(n, base, i, fd);
}
