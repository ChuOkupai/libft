/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:08:35 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 17:12:46 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	main(int ac, char **av)
{
	int i;

	i = 0;
	while (++i < ac)
		ft_putendl(ft_strforeach(av[i], &ft_toupper));
	return (0);
}
