/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 19:42:25 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 21:29:10 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_list *l;

	if (ac < 2 || ac > 3)
		return (0);
	if (!(l = ft_list_split(av[1], (ac == 2 ? NULL : av[2]))))
	{
		ft_putendl_fd("error: cannot allocate memory!", 2);
		return (1);
	}
	ft_list_sort(&l, (t_gcompare) & ft_strcmp);
	ft_list_foreach(l, (t_gfunction) & ft_putendl);
	ft_list_clear(&l, &free);
	return (0);
}
