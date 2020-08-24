/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_append.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:04:06 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/24 16:09:20 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlist_append(t_dlist *l1, t_dlist *l2)
{
	t_dlist *l;

	l = ft_dlist_last(l1);
	l2 = ft_dlist_first(l2);
	if (l)
		l->next = l2;
	if (l2)
		l2->prev = l;
	return (ft_dlist_first(l1));
}
