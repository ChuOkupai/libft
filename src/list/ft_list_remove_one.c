/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:50:46 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/10 13:05:35 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	*ft_list_remove_one(t_list **list, const void *ref, t_gcompare cmp,
		t_gfunction del)
{
	t_list	*prev;
	t_list	*l;
	void	*content;

	prev = NULL;
	l = *list;
	content = NULL;
	while (l && cmp(ref, l->content))
	{
		prev = l;
		l = l->next;
	}
	if (l)
	{
		content = ft_list_pop(&l, del);
		if (prev)
			prev->next = l;
		else
			*list = l;
	}
	return (content);
}
