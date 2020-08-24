/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:23:49 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/24 18:40:11 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlist_rev(t_dlist *l)
{
	t_dlist *prev;
	t_dlist *l2;

	if (!l)
		return (NULL);
	prev = l->prev;
	l->prev = NULL;
	while (l)
	{
		l2 = ft_dlist_merge(l, l->next, l->prev);
		l = l->prev;
	}
	if (prev)
	{
		l2->prev = prev;
		prev->next = l2;
	}
	return (l2);
}
