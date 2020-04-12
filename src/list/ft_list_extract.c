/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_extract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 11:44:16 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 18:24:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_extract(t_list **l, const void *reference,
		int (*cmp)(const void *reference, const void *content))
{
	t_list *e;
	t_list *p;

	e = *l;
	p = NULL;
	while (e && cmp(reference, e->content))
	{
		p = e;
		e = e->next;
	}
	if (e)
	{
		if (p)
			p->next = e->next;
		else
			*l = NULL;
	}
	return (e);
}
