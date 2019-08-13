/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:55:15 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/13 20:17:16 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libft.h"

void	ft_fill(char *s, size_t n)
{
	if (!n)
		return ;
	s[--n] = '\0';
	while (n)
		s[--n] = 97 + rand() % 26;
}

void	ft_benchmark(size_t n)
{
	clock_t	start, end;
	char	s[n + 1];
	
	srand(time(NULL));
	printf("size: %lu\n", n);
	ft_fill(s, n + 1);
	start = clock();
	n = ft_strlen(s);
	end = clock();
	printf("time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("len: %lu\n", n);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_benchmark(ft_atoi(argv[1]));
	return (0);
}
