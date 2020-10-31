/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:25:49 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/29 15:24:56 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	print_char(int c)
{
	int d;

	if (ft_isprint(c) && c != ' ')
		ft_putchar(c);
	else
	{
		d = ft_toprint(c);
		ft_printf((c == d ? "\\x%x" : "\\%c"), d);
	}
}

int			main(void)
{
	int i;

	i = 0;
	while (i < 128)
	{
		print_char(i);
		ft_putchar('\t' + !(++i % 8));
	}
	return (0);
}
