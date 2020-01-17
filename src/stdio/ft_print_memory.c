/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 00:38:37 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/17 22:09:31 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ctype.h"
#include "libft_stdio.h"

static void	ft_print_data(const unsigned char *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		ft_printf(" %.2hhx", s[i++]);
		if (i < n)
			ft_printf("%.2hhx", s[i++]);
	}
	while (i < 16)
	{
		ft_putstr((i & 1) ? "  " : "     ");
		i += 1 + !(i & 1);
	}
	ft_putstr(" |");
	i = 0;
	while (i < n)
	{
		ft_putchar((ft_isprint(s[i])) ? s[i] : '.');
		i++;
	}
	ft_putstr("|\n");
}

void		*ft_print_memory(const void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		ft_printf("%.16lx:", (size_t)(s + i));
		ft_print_data(s + i, (n - i < 16) ? n - i : 16);
		i += 16;
	}
	return ((void*)s);
}
