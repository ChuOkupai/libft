/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 03:08:37 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/02 11:11:47 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **list, const void *ref, t_gcompare cmp,
		t_gfunction del)
{
	t_list	*prev;
	t_list	*l;
	void	*content;

	prev = NULL;
	l = *list;
	while (l)
		if (cmp(ref, l->content))
		{
			prev = l;
			l = l->next;
		}
		else
		{
			content = ft_list_pop(&l);
			if (del)
				del(content);
			if (prev)
				prev->next = l;
			else
				*list = l;
		}
}
