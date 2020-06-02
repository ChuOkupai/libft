/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 01:12:40 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/25 02:55:04 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	char *s;

	if (ac != 3)
		return (0);
	if (!(s = ft_strtrim(av[1], av[2])))
	{
		ft_putendl_fd("error: malloc failed!", 2);
		return (0);
	}
	ft_printf("|%s|\n", s);
	free(s);
	return (0);
}
