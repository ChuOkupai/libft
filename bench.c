/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 01:13:33 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/06 01:37:34 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgen.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "libft.h"

void	ft_benchmark(int n, void*(*f)(void *, int, size_t))
{
	char	t[n];
	clock_t	start, end;
	
	start = clock();
	f(t, 0, n);
	end = clock();
	printf("time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int		main(int argc, char **argv)
{
	int n;

	if (argc == 2 && (n = ft_atoi(argv[1])) >= 0 && n <= 1000000)
	{
		ft_putendl("memset:");
		ft_benchmark(n, &memset);
		ft_putendl("ft_memset:");
		ft_benchmark(n, &ft_memset);
	}
	else
		printf("usage : %s (positive integer [0;1000000])\n", basename(argv[0]));
	return (0);
}
