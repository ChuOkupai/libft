/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:21:01 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/02 20:31:16 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

static int	print_usage(const char *bin)
{
	ft_printf("usage: %s [STRING] [SET]\n\nOptions list:\n"
	"  [STRING]  the string to split\n"
	"  [SET]     optionnal, the set of delimiters to use\n", bin);
	return (1);
}

int			main(int ac, char **av)
{
	t_list *l;

	if (ac < 2 || ac > 3)
		return (print_usage(av[0]));
	if ((l = ft_list_split(av[1], (ac == 3 ? av[2] : NULL))))
	{
		ft_list_foreach(l, (t_gfunction) & ft_putendl);
		ft_list_clear(&l, &free);
	}
	return (0);
}
