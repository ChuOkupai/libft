/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 03:08:37 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:33:31 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_list.h"

void	ft_list_remove_if(t_list **l, const void *ref,
		int (*cmp)(const void *ref, const void *content), void (*del)(void *))
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
