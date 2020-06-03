/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 00:38:37 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/03 11:10:28 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_stdio.h"
#include "ft_type.h"

static void	ft_print_data(const t_u8 *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (n - i > 1)
			ft_printf("%.2hhx%.2hhx ", s[i], s[i + 1]);
		else
			ft_printf("%.2hhx   ", s[i]);
		i += 2;
	}
	while ((i += 2) <= 16)
		ft_putstr("     ");
	while (n--)
	{
		ft_putchar(ft_isprint(*s) ? *s : '.');
		++s;
	}
	ft_putchar('\n');
}

void		*ft_print_memory(const void *s, size_t n)
{
	const t_u8	*t;
	size_t		i;

	t = s;
	i = 0;
	while (i < n)
	{
		ft_printf("%.16lx: ", (size_t)(t + i));
		ft_print_data(t + i, (n - i < 16 ? n - i : 16));
		i += 16;
	}
	return ((void*)s);
}
