/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:50:46 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/02 14:25:15 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	*ft_list_remove_one(t_list **list, const void *ref)
{
	t_list	*prev;
	t_list	*l;
	void	*content;

	prev = NULL;
	l = *list;
	while (l && l->content != ref)
	{
		prev = l;
		l = l->next;
	}
	if (l)
	{
		content = ft_list_pop(&l);
		if (prev)
			prev->next = l;
		else
			*list = l;
	}
	else
		content = NULL;
	return (content);
}
