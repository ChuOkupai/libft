/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 02:36:38 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/21 01:37:38 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include "ft_bit.h"
#include "ft_ctype.h"
#include "ft_memory.h"
#include "ft_stdio.h"
#define BUFFER_SIZE 33

void		ft_putnbr_base_fd(int n, char const *base, int fd)
{
	uint8_t		buf[BUFFER_SIZE];
	uint32_t	t;
	size_t		i;
	size_t		j;

	ft_bzero(buf, BUFFER_SIZE);
	i = 0;
	while (base[i] && ft_isgraph(base[i])
		&& base[i] != '-' && base[i] != '+' && !ft_bit_at(buf, base[i]))
		ft_bit_set(buf, base[i++]);
	if (i < 2 || base[i])
		return ;
	t = n < 0 ? -n : n;
	j = BUFFER_SIZE;
	while (t || j == BUFFER_SIZE)
	{
		buf[--j] = base[t % i];
		t /= i;
	}
	if (n < 0)
		buf[--j] = '-';
	(void)(write(fd, buf + j, BUFFER_SIZE - j) + 1);
}
