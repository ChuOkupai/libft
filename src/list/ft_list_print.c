/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 22:05:26 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 22:09:06 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_stdio.h"

void	ft_list_print(t_list *l, void (*print_func)(const void *content))
{
	ft_putchar('[');
	while (l)
	{
		print_func(l->content);
		if ((l = l->next))
			ft_printf(", ");
	}
	ft_printf("]\n");
}
