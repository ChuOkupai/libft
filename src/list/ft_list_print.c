/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 22:05:26 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 19:55:12 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_const.h"
#include "ft_list.h"
#include "ft_stdio.h"

void	ft_list_print(t_list *l, t_gprint print)
{
	ft_putstr(FT_DS_BEGIN);
	while (l)
	{
		print(l->content);
		if ((l = l->next))
			ft_printf(FT_DS_LINK);
	}
	ft_putstr(FT_DS_END);
}
