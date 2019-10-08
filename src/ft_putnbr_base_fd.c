/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 02:36:38 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/10 20:25:28 by asoursou         ###   ########.fr       */
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

	t = ABS(n);
	i = BUFFER_SIZE;
	while (t || i == BUFFER_SIZE)
	{
		buf[--i] = base[t % size];
		t /= size;
	}
	if (n < 0)
		buf[--i] = '-';
	(void)(write(fd, buf + i, BUFFER_SIZE - i) + 1);
}

void		ft_putnbr_base_fd(int n, char const *base, int fd)
{
	char	t[128];
	int		i;

	i = -1;
	ft_bzero(t, 128);
	while (base[++i] && ft_isgraph(base[i])
		&& base[i] != '-' && base[i] != '+' && !t[(int)base[i]])
		t[(int)base[i]] = 1;
	if (i > 1 && !base[i])
		ft_print(n, base, i, fd);
}
