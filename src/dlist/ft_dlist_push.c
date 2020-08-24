/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:46:59 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/24 20:17:20 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlist_push(t_dlist **list, t_dlist *elem)
{
	t_dlist *l;

	if (!elem)
		return (NULL);
	l = *list;
	*list = elem;
	if (l)
	{
		if ((elem->prev = l->prev))
			l->prev->next = elem;
		l->prev = elem;
	}
	elem->next = l;
	return (elem);
}
