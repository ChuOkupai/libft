/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:16:12 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/13 00:23:54 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_stdio.h"

void	ft_list_print_fd(t_list *l,
		void (*print)(const void *content, int fd), int fd)
{
	ft_putchar_fd('[', fd);
	while (l)
	{
		print(l->content, fd);
		if ((l = l->next))
			ft_dprintf(fd, ", ");
	}
	ft_dprintf(fd, "]\n");
}
