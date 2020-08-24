/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 01:07:59 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/25 01:10:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlist_insert(t_dlist **l, t_dlist *elem, t_gcompare cmp)
{
	t_dlist *h;

	h = *l;
	if (!h || cmp(elem->content, h->content) <= 0)
		return (ft_dlist_push(l, elem));
	else if (!h->next)
		return (ft_dlist_push_back(l, elem));
	return (ft_dlist_insert(&h->next, elem, cmp));
}
