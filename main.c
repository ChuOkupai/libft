/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 00:49:50 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/06 01:41:46 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_putnbr(ft_atoi_base(argv[1], argv[2]));
		ft_putchar('\n');
		ft_memprint(argv[2], ft_strlen(argv[2]) + 1);
	}
	return (0);
}
