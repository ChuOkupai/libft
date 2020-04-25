/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:34:59 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 17:06:27 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static t_list	*merge(t_list *l1, t_list *l2, t_gcompare cmp)
{
	if (!l1)
		return (l2);
	if (!l2)
		return (l1);
	if (cmp(l1->content, l2->content) > 0)
	{
		l2->next = merge(l1, l2->next, cmp);
		return (l2);
	}
	l1->next = merge(l1->next, l2, cmp);
	return (l1);
}

void			ft_list_sort(t_list **l, t_gcompare cmp)
{
	t_list *prev;
	t_list *next;

	if (!*l || !(*l)->next)
		return ;
	prev = *l;
	next = prev->next;
	while (next && (next = next->next))
	{
		prev = prev->next;
		next = next->next;
	}
	next = prev->next;
	prev->next = NULL;
	ft_list_sort(&(*l), cmp);
	ft_list_sort(&next, cmp);
	*l = merge(*l, next, cmp);
}
