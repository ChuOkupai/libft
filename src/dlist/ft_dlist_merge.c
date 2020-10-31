/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:04:06 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/30 14:21:58 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlist_merge(t_dlist *l1, t_dlist *l2)
{
	t_dlist *last;

	if (!l1)
		return (l2);
	if (!l2)
		return (l1);
	l2 = ft_dlist_first(l2);
	last = ft_dlist_last(l1);
	l2->prev = last;
	last->next = l2;
	return (ft_dlist_first(l1));
}
