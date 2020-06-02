/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 01:12:40 by asoursou          #+#    #+#             */
/*   Updated: 2020/05/28 16:43:52 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_list *l;

	if (ac < 2 || ac > 3)
		return (0);
	if ((l = ft_list_split(av[1], (ac == 3 ? av[2] : NULL))))
	{
		ft_list_print(l, (t_gprint) & ft_putstr);
		ft_list_clear(&l, &free);
	}
	return (0);
}
