/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 11:25:49 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/17 19:46:03 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	print_char(int c)
{
	int p;

	if (ft_isprint(c))
	{
		if (c == '\'')
			ft_putstr("'\\''");
		else
			ft_printf("'%c'", c);
	}
	else
	{
		p = ft_toprint(c);
		ft_printf((c == p ? "'\\x%hhx'" : "'\\%c'"), p);
	}
}

int			main(void)
{
	int		i;
	char	c;

	i = -1;
	while (++i < 128)
	{
		c = i;
		print_char(c);
		ft_putchar(i % 8 == 7 ? '\n' : '\t');
	}
	return (0);
}
