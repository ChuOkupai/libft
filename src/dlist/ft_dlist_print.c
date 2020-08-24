/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:45:46 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/24 20:17:07 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_const.h"
#include "ft_dlist.h"
#include "ft_stdio.h"

void	ft_dlist_print(t_dlist *l, t_gprint print)
{
	ft_putchar('[');
	while (l)
	{
		print(l->content);
		if ((l = l->next))
			ft_putstr(", ");
	}
	ft_putstr("]\n");
}
