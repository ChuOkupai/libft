/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:34:59 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/05 23:43:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_merge(t_list *l1, t_list *l2,
				int (*cmp)(const void *, const void *))
{
	if (!l1)
		return (l2);
	if (!l2)
		return (l1);
	if (cmp(l1->content, l2->content) > 0)
	{
		l2->next = ft_merge(l1, l2->next, cmp);
		return (l2);
	}
	l1->next = ft_merge(l1->next, l2, cmp);
	return (l1);
}

void			ft_lstsort(t_list **l, int (*cmp)(const void *, const void *))
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
	ft_lstsort(&(*l), cmp);
	ft_lstsort(&next, cmp);
	*l = ft_merge(*l, next, cmp);
}
