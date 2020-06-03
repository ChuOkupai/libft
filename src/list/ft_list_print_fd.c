/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:16:12 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/03 13:36:35 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_stdio.h"

void	ft_list_print_fd(t_list *l, t_gprint_fd print_fd, int fd)
{
	ft_putchar_fd('[', fd);
	while (l)
	{
		print_fd(l->content, fd);
		if ((l = l->next))
			ft_putstr_fd(", ", fd);
	}
	ft_putstr_fd("]\n", fd);
}
