/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 13:27:55 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/23 13:54:46 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <time.h>
#include "libft.h"

static int	usage(const char *bin)
{
	ft_printf("Usage: %s [N] [MAX]\n\n"
	"Prints [N] random numbers using the Xoroshiro256** PRNG.\n\n"
	"[MAX] is optional and indicates the maximum value of the output - 1.\n"
	"This value must be between 1 and %lu.\n", bin, ULONG_MAX);
	return (1);
}

int			main(int ac, char **av)
{
	t_u64 n;
	t_u64 max;

	if (ac < 2 || ac > 3)
		return (usage(*av));
	n = ft_strtoul(av[1], NULL, 10);
	max = ac == 3 ? ft_strtoul(av[2], NULL, 10) : ULONG_MAX;
	if (!max)
		return (usage(*av));
	ft_seed(time(NULL));
	while (n--)
		ft_printf("%lu\n", ft_rand() % max);
	return (0);
}
