/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:23:49 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/26 12:54:13 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

static t_dlist	*swap(t_dlist *l)
{
	t_dlist *t;

	t = l->prev;
	l->prev = l->next;
	l->next = t;
	return (l);
}

t_dlist			*ft_dlist_rev(t_dlist *l)
{
	t_dlist *prev;
	t_dlist *l2;

	if (!l)
		return (NULL);
	prev = l->prev;
	l->prev = NULL;
	while (l)
	{
		l2 = swap(l);
		l = l->prev;
	}
	if (prev)
	{
		l2->prev = prev;
		prev->next = l2;
	}
	return (l2);
}
