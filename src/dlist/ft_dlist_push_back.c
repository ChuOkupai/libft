/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_push_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:15:29 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/30 14:49:46 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist	*ft_dlist_push_back(t_dlist **l, void *content)
{
	t_dlist *elem;

	if (!(elem = ft_dlist_new(content)))
		return (NULL);
	if (*l)
	{
		elem->prev = ft_dlist_last(*l);
		elem->prev->next = elem;
	}
	else
		*l = elem;
	elem->next = NULL;
	return (elem);
}
