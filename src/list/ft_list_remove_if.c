/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 03:08:37 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/10 13:05:57 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **list, const void *ref, t_gcompare cmp,
		t_gfunction del)
{
	t_list *prev;
	t_list *l;

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
			ft_list_pop(&l, del);
			if (prev)
				prev->next = l;
			else
				*list = l;
		}
}
