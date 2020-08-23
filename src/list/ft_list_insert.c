/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 00:00:15 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 16:32:07 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_insert(t_list **l, t_list *elem, t_gcompare cmp)
{
	t_list *prev;
	t_list *i;

	if (!elem)
		return (NULL);
	prev = NULL;
	i = *l;
	while (i && cmp(elem->content, i->content) > 0)
	{
		prev = i;
		i = i->next;
	}
	if (prev)
		prev->next = elem;
	return (ft_list_push((prev ? &i : l), elem));
}
