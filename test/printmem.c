/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 21:36:12 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 21:37:25 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_print_memory(av[1], ft_strlen(av[1]));
	return (0);
}
