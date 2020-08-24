/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:35:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/24 16:44:52 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_dlist.h"

void	*ft_dlist_pop(t_dlist **list, t_gfunction del)
{
	t_dlist	*l;
	void	*content;

	l = *list;
	*list = l->next;
	if (del)
	{
		del(l->content);
		content = NULL;
	}
	else
		content = l->content;
	if (l->prev)
		l->prev->next = l->next;
	if (l->next)
		l->next->prev = l->prev;
	free(l);
	return (content);
}
