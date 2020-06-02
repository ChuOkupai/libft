/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strpbrk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:52:55 by asoursou          #+#    #+#             */
/*   Updated: 2019/12/29 20:55:44 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

int	main(int ac, char **av)
{
	char *s1;
	char *s2;

	if (ac == 3)
	{
		s1 = ft_strpbrk(av[1], av[2]);
		s2 = strpbrk(av[1], av[2]);
		if (s1 != s2)
			ft_printf("ft >%s$\norg >%s$\n", s1, s2);
	}
	return (0);
}
