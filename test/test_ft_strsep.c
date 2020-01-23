/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strsep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:18:27 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/17 20:18:27 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

int main(int ac, char **av)
{
	char *s;
	char *s2;
	char *p;

	if (ac != 3)
		return (-1);
	ft_printf("s = %s\ndelim = %s\n\n", av[1], av[2]);
	if (!(s2 = ft_strdup(av[1])))
		return (-1);
	s = s2;
	while (s && (p = strsep(&s, av[2])))
		ft_printf("s = %s\np = %s\n", s, p);
	free(s2);
	if (!(s2 = ft_strdup(av[1])))
		return (-1);
	s = s2;
	ft_putchar('\n');
	while (s && (p = ft_strsep(&s, av[2])))
		ft_printf("s = %s\np = %s\n", s, p);
	free(s2);
	return (0);
}
