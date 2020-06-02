/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 15:54:41 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 14:17:07 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	char	*s;
	size_t	n;

	if (ac != 3)
		return (0);
	n = ft_strlen(av[1]) + 1;
	if (!(s = ft_memdup(av[1], n, ft_strtoul(av[2], NULL, 10))))
	{
		ft_putendl_fd("error: malloc failed!", 2);
		return (-1);
	}
	ft_print_memory(s, n);
	free(s);
	return (0);
}
