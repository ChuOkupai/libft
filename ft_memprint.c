/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 00:38:37 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/18 03:48:58 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	ft_puthex(unsigned char c)
{
	char *base;

	base = "0123456789abcdef";
	ft_putchar(base[c >> 4]);
	ft_putchar(base[c & 15]);
}

static void	ft_print_data(const char *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		ft_putchar(' ');
		ft_puthex(s[i++]);
		if (i < n)
			ft_puthex(s[i++]);
	}
	while (i < 16)
	{
		write(STDOUT_FILENO, "     ", (i & 1) ? 2 : 5);
		i += (i & 1) ? 1 : 2;
	}
	write(STDOUT_FILENO, " |", 2);
	i = 0;
	while (i < n)
	{
		ft_putchar((ft_isprint(s[i])) ? s[i] : '.');
		i++;
	}
	write(STDOUT_FILENO, "|\n", 2);
}

void		*ft_memprint(const void *s, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < n)
	{
		j = 8 * sizeof(size_t);
		while (j > 0)
			ft_puthex((size_t)(s + i) >> (j -= 8));
		ft_putchar(':');
		ft_print_data(s + i, (n - i < 16) ? n - i : 16);
		i += 16;
	}
	return ((void*)s);
}
