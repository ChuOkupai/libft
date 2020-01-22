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

#include "libft.h"

int main(int ac, char **av)
{
	unsigned int n;

	if (ac == 2)
		ft_print_memory(av[1], ft_strlen(av[1]));
	n = (unsigned int)0x01020304;
	ft_print_memory(&n, sizeof(unsigned int));
	return (0);
}
