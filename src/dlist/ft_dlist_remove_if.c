/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_remove_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:30:39 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/24 17:30:43 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	ft_dlist_remove_if(t_dlist **list, const void *ref, t_gcompare cmp,
		t_gfunction del)
{
	t_dlist *l;

	l = *list;
	while (l)
		if (cmp(ref, l->content))
			l = l->next;
		else
		{
			if (l == *list)
				*list = l->next;
			ft_dlist_pop(&l, del);
		}
}
