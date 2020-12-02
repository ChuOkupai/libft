/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:34:59 by asoursou          #+#    #+#             */
/*   Updated: 2020/12/02 17:08:49 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static t_list	*ft_cut(t_list *l)
{
	t_list *next;

	if (!l || !l->next)
		return (NULL);
	next = l->next;
	l->next = NULL;
	return (next);
}

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
	t_list *right;

	if (!(right = ft_cut(*l)))
		return ;
	ft_list_sort(&right, cmp);
	*l = merge(*l, right, cmp);
}
