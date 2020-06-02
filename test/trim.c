/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 15:54:41 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 21:39:10 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	char *s;

	if (ac < 2 || ac > 3)
		return (0);
	if (!(s = ft_strtrim(av[1], (ac == 3 ? av[2] : NULL))))
	{
		ft_putendl_fd("error: malloc failed!", 2);
		return (1);
	}
	ft_putendl(s);
	free(s);
	return (0);
}
