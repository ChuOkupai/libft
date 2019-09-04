/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 02:36:38 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/04 03:10:10 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(unsigned int n, char const *base, unsigned int size,
			int fd)
{
	if (n > size - 1)
	{
		ft_print(n / size, base, size, fd);
		n %= size;
	}
	ft_putchar_fd(base[n], fd);
}

void		ft_putnbr_base_fd(int n, char const *base, int fd)
{
	unsigned int i;

	i = 0;
	while (base[i])
		if (base[i] == '+' || base[i] == '-' || !ft_isgraph(base[i++])
			|| ft_strchr(base + i, base[i - 1]))
			return ;
	if (i < 2)
		return ;
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_print(((n < 0) ? -n : n), base, i, fd);
}
