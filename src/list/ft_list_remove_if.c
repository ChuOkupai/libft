/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 03:08:37 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/24 17:19:02 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **l, const void *ref, t_gcompare cmp,
		t_gfunction del)
{
	t_list *prev;
	t_list *c;

	prev = NULL;
	c = *l;
	while (c)
		if (cmp(ref, c->content))
		{
			prev = c;
			c = c->next;
		}
		else
		{
			ft_list_pop(&c, del);
			if (prev)
				prev->next = c;
			else
				*l = c;
		}
}
