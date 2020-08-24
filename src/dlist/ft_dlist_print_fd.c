/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_print_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:46:21 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/24 16:46:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include "ft_stdio.h"

void	ft_dlist_print_fd(t_dlist *l, t_gprint_fd print_fd, int fd)
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
