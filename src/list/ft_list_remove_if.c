/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 03:08:37 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/03 06:37:19 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_list_remove_if(t_list **l, const void *reference,
		int (*cmp)(const void *, const void *), void (*del)(void *))
{
	t_list *prev;
	t_list *c;

	prev = NULL;
	c = *l;
	while (c)
		if (cmp(c->content, reference))
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
