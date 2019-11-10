/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_extract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 11:44:16 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:32:24 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list	*ft_list_extract(t_list **l, const void *ref,
		int (*cmp)(const void *ref, const void *content))
{
	t_list *e;
	t_list *p;

	e = *l;
	p = NULL;
	while (e && cmp(e->content, ref))
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
